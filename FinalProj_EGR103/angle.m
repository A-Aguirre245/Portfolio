clear

xDist = 512;
yDist = 512

m = mobiledev;
                % Flip to back Camera
                cam = camera(m,'back');
                % Focus camera
                cam.Resolution='1280x720';
                cam.Flash = 'on';
                cam.Autofocus = 'on';
                % Take Photo
                img = snapshot(cam,'immediate');
                imwrite(img,'latestPicture.jpg');
                image = imread('latestPicture.jpg');
                % Show photo
                %imtool(image);
                % Color Values
                g_channel=image(:,:,2);
                r_channel=image(:,:,1);
                b_channel=image(:,:,3);
                % Color ratios
                gr_ratio=double(g_channel)./double(r_channel); % Green red ratio
                gb_ratio=double(g_channel)./double(b_channel); % Green blue ratio
                gr_ratio(isnan(gr_ratio)) = 0;
                gb_ratio(isnan(gb_ratio)) = 0;
                % Pull out green values
                g_bin = (gb_ratio>= 1.50 & gr_ratio>= 1.50);
                % Turns Photo black and white
                black_and_white=bwareaopen(g_bin,80);
                % Fills in holes
                black_and_white=imfill(g_bin,"holes");
                black_and_white = bwareaopen(g_bin,80);
                % Shows photo
                %imshow(black_and_white)
                % Finds the center of the markers
                dotPlacements = regionprops('table',black_and_white,'Centroid');
                UsefulTable = dotPlacements{:,:};
                totalX = (UsefulTable(1,1) + UsefulTable(2,1) + UsefulTable(3,1) + UsefulTable(4,1));
                totalY = (UsefulTable(1,2) + UsefulTable(2,2) + UsefulTable(3,2) + UsefulTable(4,2));
                numVal = 4;
                % Averages out the x and y placements of markers
                AvgX = totalX/numVal;
                AvgY = totalY/numVal;
                % Finds the placement of the markers to the left and right
                topXdist = (UsefulTable(1,1) + UsefulTable(2,1))/2;
                bottomXdist = (UsefulTable(3,1) + UsefulTable(4,1))/2;
                % Distance from target
                %Finds the distance between the markers
                distXAvg = bottomXdist - topXdist;
                % Finds the distance from target in X
                multipliedX = distXAvg/(6941);
                Xroot = nthroot(multipliedX, -1);
                % Finds the placement of the markers to the top and bottom
                rightYdist = (UsefulTable(1,2) + UsefulTable(3,2))/2;
                leftYdist = (UsefulTable(4,2) + UsefulTable(4,2))/2;
                % Finds the distance between the markers
                distYavg = abs(leftYdist - rightYdist);
                % Finds the distance from target in X
                multipliedY = distYavg/(3496.6);
                Yroot = (nthroot(multipliedY, -1.004));
                %Averages out the two distances
                %targetDist = (Yroot + Xroot)/2;
                fprintf('Distance from Target:%.2f inches \n', Xroot);

                % Finding the Horizontal Angle
                XdirectionTarget = (AvgX - 640);
                % Convert from pixles to inches
                pixleRatio = XdirectionTarget/distXAvg;
                PixleConversion = pixleRatio * 8;
                % Find horizontal angle of the target
                HorizontalAngle = atand(PixleConversion/ Xroot);
                xAngle = 90 + HorizontalAngle;
                fprintf('Horizontal Angle:%.f degrees \n',  xAngle);
                xAngle = xAngle * 5.7;
                xDist = xAngle - xDist;
                fprintf('Horizontal dist:%.f degrees \n',  xDist);

                
                % Finding the Vertical Angle
                % Pull out Red values
                r_bin = (gr_ratio >= .60 & b_channel >= 170.0 & gr_ratio >= 1.7 & r_channel <= 50.0);
                % Turns Photo black and white
                b_and_w=bwareaopen(r_bin,50);
                % Fills in holes
                b_and_w = imfill(r_bin,"holes");
                bottomLine = regionprops('table', b_and_w, 'Centroid');
                %imshow(b_and_w)
                % imtool(b_and_w)
                b_and_w = bwareaopen(r_bin,80);
                Table = bottomLine{:,:};
                zero = (Table(2,2) + Table(1,2))/2;
                YdirectionTarget = abs(zero - AvgY);
                % Converts from pixles into inches
                YpixleRatio = YdirectionTarget/distYavg;
                YPixleConversion = YpixleRatio * 8;
                APixleConversion = YPixleConversion + 4;
                % Find the Vertical Angle
                yAngle = atand(APixleConversion/ Xroot);
                fprintf('Vetical Angle:%.f degrees \n',  yAngle);
                
                yAngle = yAngle * 5.7;

                yDist = yAngle - yDist;
                fprintf('Vetical dist:%.f degrees \n',  yDist);
                
            