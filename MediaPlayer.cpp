/*Title: MediaPlayer.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 11/16/2020
Description: This class defines the header file for the media player for project 5
*/

#include "MediaPlayer.h"

//MediaPlayer - Default Constructor
//creates a new MediaPlayer
MediaPlayer::MediaPlayer(){
  LoadCatalog("proj5_media.txt");
}

//MediaPlayer - Overloaded Constructor
//creates a new MediaPlayer and passes the media filename
MediaPlayer::MediaPlayer(string filename){
  LoadCatalog(filename);
}

//~MediaPlayer - Destructor
//deletes MediaPlayer
MediaPlayer::~MediaPlayer(){
  for (unsigned int i = 0; i < m_mediaCatalog.size(); i++) {
    delete m_mediaCatalog.at(i);
  }
  for (unsigned int i = 0; i < m_mediaCatalog.size(); i++) {
    m_mediaCatalog.erase(m_mediaCatalog.begin() + i);
  }
}

//LoadCatalog(string)
//loads the file into the m_mediaCatalog (as media)
void MediaPlayer::LoadCatalog(string filename){
  string title;
  string artist;
  string type;
  string year;
  string rank;
  int count = 0;  
  ifstream mediaCatalog(filename);

  if (mediaCatalog.is_open()){  
    while(getline(mediaCatalog, title, ';')) {
      getline(mediaCatalog, artist, ';');
      getline(mediaCatalog, type, ';');
      getline(mediaCatalog, year, ';');
      getline(mediaCatalog, rank);
      m_mediaCatalog.push_back(new Media(title, artist, type, stoi(year), stoi(rank)));
      count++;
    }
  }
  else{
    cout << "file not found" << endl;
  }
  mediaCatalog.close();
  cout << count << " media files loaded." << endl;
}

//MainMenu()
//manages the application and the menu
void MediaPlayer::MainMenu(){
  int option = 0;
  while(option != 5) {
    option = 0;
    //validate user input
    while (option < 1 || option > 5) {
      cout << "What would you like to do?\n"
	                    "1. Display Media by Type and Year\n"
	                    "2. Add Media to Playlist\n"
	                    "3. Display Playlist\n"
	                    "4. Sort Playlist by Year\n"
	"5. Quit\n";
      cin >> option;
    }
    switch (option) {
    case 1:
      cout << DisplayMedia() << " media found." << endl;
      break;
    case 2:
      AddMedia();
      break;
    case 3:
      DisplayPlaylist();
      break;
    case 4:
      SortPlaylist();
      break;
    case 5:
    default:
      break;
    }
  }
  cout << "Thank you for using the UMBC Media Player" << endl;
}

//DisplayMedia()
//lists all media (numbered) for that year and returns int
//               of number found with that criteria
int MediaPlayer::DisplayMedia(){
  string type = "";
  int year = 0;
  int count = 0;

  //validate user input
  while(type != "music" && type != "podcast") {
    cout << "Which media type do you want to display?\n"
                      "music\n"
                      "podcast\n";
    cin >> type;
  }
  while(year < 1958 || year > 2020){
    cout << "Which year would you like to display? (1958-2020)" << endl;
    cin >> year;
  }

  //display all music/podcasts from that year 
  cout << "******" << year << "*****" << endl;
  for(unsigned int i = 0; i < m_mediaCatalog.size(); i++){
    if(m_mediaCatalog.at(i)->GetYear() == year && m_mediaCatalog.at(i)->GetType() == type) {
      cout << i + 1 << ". " << *m_mediaCatalog.at(i);
      count++;
    }
  }

  //no music/podcast that year
  if(count == 0)
    cout << "Sorry no " << type << " for " << year << endl;

  return count;
}

//AddMedia()
//displays the current list and adds media
//to the m_playList
void MediaPlayer::AddMedia(){
  if(m_playList.IsFull())
    cout << "Sorry playlist is full" << endl;
  else{
    int add = 0;
    int media = 0;
    
    DisplayPlaylist();
    cout << "Choose the media you would like to add to the playlist." << endl;
    media = DisplayMedia();

    //display media and amount of that time found
    if(media !=0){
      cout << media << " media found." << endl; 
      cout << "Enter the number of the media you would like to add:" << endl;
      cin >> add;
      
      //validate input
      while(add <= 0 || add > 6300){
	cout << "sorry not an option" << endl;
	cout << "Enter the number of the media you would like to add:" << endl;
	cin >> add;
      }
       m_playList.Enqueue(m_mediaCatalog.at(add - 1));

       cout << m_mediaCatalog.at(add - 1)->GetTitle() << " by " << m_mediaCatalog.at(add - 1)->GetArtist() \
	    << " added to the playlist" << endl;
    }
  }
}

//DisplayPlaylist()
//displays the playlist
void MediaPlayer::DisplayPlaylist(){
  if(m_playList.IsEmpty() == 1)
    cout << "The playlist is currently empty" << endl;
  else {
    for(int i = 0; i < m_playList.Size(); i++) {
      cout << i + 1 << ". " << m_playList.At(i)->GetTitle() << " by " << m_playList.At(i)->GetArtist()\
	   << " from " << m_playList.At(i)->GetYear() << endl;
    }
  }
}

//SortPlaylist()
//sorts the playlist by year
void MediaPlayer::SortPlaylist(){
  if(m_playList.IsEmpty() == 1)
    cout << "The playlist is currently empty" << endl;
  else {
    m_playList.Sort();
    cout << "Done sorting by year" << endl;
    cout << m_playList.Size() << " items sorted." << endl;

  }
}
