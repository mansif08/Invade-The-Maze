On Linux System : 

	1.SDL2.h,SDL2_image.h,SDL2_ttf.h,SDL2_mixer.h must be installed.
	
	2.Audio,Images,struct folder has to be downloaded in th same directory. 
	
	3.Go to struct folder on terminal using the command :
	cd struct
	
	4.Compile on terminal using the command :
	g++ main.cpp -w -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o last.cpp && ./last.cpp
