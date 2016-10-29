//program meant to make it easy to download mp3s from youtube using 
//youtube-dl from https://github.com/rg3/youtube-dl
//REQUIRES youtube-dl to be installed.

//to make program run from anywhere(aka just calling it) 
//add <THIS> to end of ~/.bashrc file
//THIS = export PATH="$PATH:<Path/to/file>"


#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		if(argv[0])
		{
			cout << "just put URL(of a song or playlist) after the program name" << endl;
			cout << "EXAMPLE ->  youtubeMP3 <someURL>" << endl;
		}
		else
		{
			cout << cout << "Usage: <program name> <URL>" << endl;
		}

		exit(1);
	}

	//parameters used to download mp3 file from youtube video
	string parameters = "youtube-dl -x --audio-format mp3 --audio-quality 0 --embed-thumbnail --add-metadata ";
	parameters += argv[1];

	//testing output
	//cout << parameters << endl;
	
	//does system call to youtube-dl with url
	system(parameters.c_str());	
	
	//does system call to move file to Music folder
	system("mv ./*.mp3 ~/Music/");

	return 0;
}
