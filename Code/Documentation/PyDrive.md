# PyDrive

This documents how to set up PyDrive on Rpi to upload figures and csv files to google drive.

Refer to official documentation [here](https://googleworkspace.github.io/PyDrive/docs/build/html/index.html).

## Install PyDrive

```bash
pip3 install PyDrive
```

## PyDrive configuration

Official document is [here](https://googleworkspace.github.io/PyDrive/docs/build/html/quickstart.html#authentication) but it didn't work for me. I did some minor modifications:

1. Go to APIs Console and make your own project.
2. Search for ‘Google Drive API’, select the entry, and click ‘Enable’.
3. Select ‘Credentials’ from the left menu, click ‘Create Credentials’, select ‘OAuth client ID’.
4. Now, the product name and consent screen need to be set -> click ‘Configure consent screen’ and follow the instructions. Once finished: Select ‘Application type’ to be Desktop application.
5. Enter an appropriate name.
6. Click ‘Create’.
7. Click ‘Download JSON’ on the right side of Client ID to download client_secret_<really long ID>.json.
8. The downloaded file has all authentication information of your application. Rename the file to “client_secrets.json” and place it in your working directory.
9. Create a quickstart.py file and copy and paste the following code.

```python
from pydrive.auth import GoogleAuth

gauth = GoogleAuth()
gauth.CommandLineAuth()
```

Run quickstart.py and follow the authorizations from command lines as a quick test that connection is working.
