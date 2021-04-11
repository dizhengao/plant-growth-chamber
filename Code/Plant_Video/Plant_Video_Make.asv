clear

date_start=datetime([2021 04 06]);
date=date_start;
formatOut = 'yymmdd';

video = VideoWriter('Plant_Growth_0406_to_0410','MPEG-4'); %create the video object
video.FrameRate=4;% define the frame rate
open(video); %open the file for writing

for i=1:5
    day=datestr(date,formatOut);
    address=['/Users/wc289/Google Drive (zd101iot@gmail.com)/' day '/*.jpg'];

    Files=dir(address);
    for k=1:length(Files) % For each file
        I = imread([Files(k).folder '/' Files(k).name]); %read the next image
        writeVideo(video,I); %write the image to file
    end
    date=date+days(1);
end
close(video); %close the file


