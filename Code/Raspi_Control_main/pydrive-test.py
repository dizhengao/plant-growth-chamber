from pydrive.drive import GoogleDrive
from pydrive.auth import GoogleAuth

gauth = GoogleAuth()
gauth.CommandLineAuth()

drive = GoogleDrive(gauth) # Create GoogleDrive instance with authenticated GoogleAuth instance.

# Create GoogleDriveFile instance with title 'Hello.txt'.
file1 = drive.CreateFile({'title': 'Hello.txt'})
file1.Upload() # Upload the file.
print('title: %s, id: %s' % (file1['title'], file1['id'])) # title: Hello.txt, id: {{FILE_ID}}
        #---------------------------------mode 1: save data to csv files-------------------------
            fname = 'log_' + current_day + '.csv'
            if not os.path.isfile(fname): # in order to save each day's data into individual .csv files, we first check if a file coresponding to that date exists, if not we create the file and add header as the first line.
                os.system('echo ' + header + ' >> ' + fname)

            datalog = str(current_time) + ',' + str(line)
            os.system('echo ' + datalog + ' >> ' + fname)

