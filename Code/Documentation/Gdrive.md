# Google drive

>This document is not longer used, as I only want to upload single file to google drive at a time instead of sync a whole folder. Use the python package [PyDrive](https://googleworkspace.github.io/PyDrive/docs/build/html/index.html) instead, check [this](PyDrive.md).

This documents how to set up google drive sync on Rpi to save a copy of data and images on cloud.

Ref: We use [Grive2](https://github.com/vitalif/grive2) here. Alternative: [drive](https://github.com/odeke-em/drive) and [rclone](https://medium.com/@artur.klauser/mounting-google-drive-on-raspberry-pi-f5002c7095c2).

## Installing Grive2

Refer to official documentation [here](http://yourcmc.ru/wiki/Grive2#Installation).

Install all dependencies by

```bash
sudo apt-get update
sudo apt-get install git cmake build-essential libgcrypt20-dev libyajl-dev libboost-all-dev libcurl4-openssl-dev libexpat1-dev libcppunit-dev binutils-dev debhelper zlib1g-dev dpkg-dev pkg-config
```

Then clone the repo (or just [download the zip file](https://github.com/vitalif/grive2/archive/master.zip) and unzip it) and cd into it.

```bash
git clone https://github.com/vitalif/grive2
cd grive2
```

Install by

```bash
mkdir build
cd build
cmake ..
make -j4
sudo make install
```

If installation is successful then you should be able to run `grive` from command line. By `grive -v` I got

```bash
grive version 0.5.2-dev Apr  6 2021 11:15:37
```

## Google Drive configuration

Google restricted access for unapproved applications so there are a few more steps required to configure Grive2. Follow instructions [here](https://github.com/Dishendramishra/linux-setup/blob/master/README.md#google-drive).

Note: following on the steps shown above, make sure you go to OAuth 'consent screen' > 'Test Users' > 'ADD USERS' and add your email there.

## Usage

When running Grive2 for the first time, we need to run `grive -a` with OAuth2 details to grant permission to Grive to access to your Google Drive.

```bash
cd <path-to-your-directory>
grive -a --id <client_id> --secret <client_secret>
```

 Follow the steps to authenticate the OAuth2 client to allow it to access your drive folder.