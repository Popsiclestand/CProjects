from email.MIMEMultipart import MIMEMultipart
from email.MIMEBase import MIMEBase
from email.MIMEText import MIMEText
from email.Utils import COMMASPACE, formatdate
from email import Encoders

theR_db = MySQLdb.connect(
    host = 'ther-db-master.prod.hulu.com',
    user = 'ther_reader',
    passwd = 'hulu12312',
    db = 'hulu',
    cursorclass=MySQLdb.cursors.DictCursor,
    use_unicode = True
    )

def query_run(db, query):
    cur = db.cursor()
    cur.execute(query)
    result = cur.fetchall()
    cur.close()
    value = result
    return value

def send_mail(send_from, to, cc, subject, text, files, server='smtp.els.hulu.com'):
    assert type(to)==list
    assert type(files)==list
    assert type(cc)==list

    msg = MIMEMultipart()
    msg['From'] = send_from
    msg['To'] = COMMASPACE.join(to)
    msg['CC'] = COMMASPACE.join(cc)
    msg['Date'] = formatdate(localtime=True)
    msg['Subject'] = subject

    msg.attach( MIMEText(text) )

    for f in files:
        part = MIMEBase('application', "octet-stream")
        part.set_payload( open(f,"rb").read() )
        Encoders.encode_base64(part)
        part.add_header('Content-Disposition', 'attachment; filename="%s"' % os.path.basename(f))
        msg.attach(part)

    smtp = smtplib.SMTP(server)
    smtp.sendmail(send_from, to + cc, msg.as_string())
    smtp.close()

def collect_data():
    recs = query_run(theR_db,"""SELECT a.id AS 'Asset ID',cp.id AS 'CP_ID',cp.name AS 'CP_Name',cp.manager AS 'CPM',se.title AS 'Series_Title',a.title AS 'Asset_Title',s.number AS 'Season_Num',a.episode_number AS 'Episode_Num',se.id AS 'Series_ID',s.id AS 'Season_ID',a.hulu_approved AS 'HA=',v.regions AS "Regions",COUNT(vaw.id) AS "VAW"
                                FROM asset a
                                LEFT JOIN video_availability_window vaw ON a.id = vaw.asset_id
                                JOIN season s on a.season_id = s.id
                                JOIN series se on a.series_id = se.id
                                JOIN content_partner cp on a.cp_id = cp.id
                                JOIN video v on v.asset_id = a.id
                                WHERE a.is_deleted=0
                                AND a.created > "2015-09-01 00:07:00"
                                AND v.regions != "JP"
                                GROUP BY a.id
                                HAVING count(vaw.id) = 0
                                ORDER BY 4,3,5,7,8;""")
    return recs

def build_csv(recs):
    f = []
    if recs:
        f = 'noah_check.csv'
        csv = 'asset_id,cp,cp_name,cpm,series_title,asset_title,ep_number,series_id,series,season_id,season,region,vaw\n'
        for r in recs:
            csv += '%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,\n' % (r['Asset ID'], r['CP_ID'], r['CP_Name'], r['CPM'], r['Series_Title'], r['Asset_Title'], r['Season_Num'], r['Episode_Num'], r['Series_ID'], r['Season_ID'], r['HA='], r['Regions'], r['VAW'])
        with open(f,'w+') as csv_file:
            csv_file.write(csv.encode('ascii','ignore'))
    return f

if __name__ == '__main__':
    recs = collect_data()
    f = build_csv(recs)
    send_mail('sar@hulu.com',['mark.forbes@hulu.com'],['matthew.dome@hulu.com'],'Classic-Only Content Pull',"Attached is a list of assets that are currently classic-only.\n\n-Sar\n\n",[f])
    os.remove(f)











