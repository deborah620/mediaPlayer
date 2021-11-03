/*Title: Media.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 11/16/2020
Description: This class defines the header file for media for project 5
*/

#include "Media.h"

//Media - Default Constructor
//creates a default media
Media::Media(){
  m_title =  "It's All In The Game";
  m_artist = "Tommy Edwards";
  m_type = "music";
  m_year = 1958;
  m_rank = 1;
}

//Media - Overloaded Constructor
//creates a media entry based on passed parameters
Media::Media(string title, string artist, string type, int year, int rank){
  m_title = title;
  m_artist = artist;
  m_type = type;
  m_year = year;
  m_rank = rank;
}

//GetTitle()
//return title
string Media::GetTitle()const{
  return m_title;
}

//GetArtist()
//return artist
string Media::GetArtist()const{
  return m_artist;
}

//GetType()
//return type
string Media::GetType()const{
  return m_type;
}

//GetYear()
//return year
int Media::GetYear()const{
  return m_year;
}

//GetRank()
//return rank (1-100 from that year)
int Media::GetRank()const{
  return m_rank;
}

//SetTitle(string)
//set title
void Media::SetTitle(string title){
  m_title = title;
}

//SetArtist(string)
//set artist
void Media::SetArtist(string artist){
  m_artist = artist;
}

//SetType(string)
//set type
void Media::SetType(string type){
  if(type == "music" || type == "podcast")
    m_type = type;
}

//SetYear(int)
//set year
void Media::SetYear(int year){
  if(year >= 1958 && year <= 2020)
    m_year = year;
}

//SetRank(int)
//set rank
void Media::SetRank(int rank){
  if(rank >= 1 && rank <= 100) 
    m_rank = rank;
}

//Overloaded << operator
//returns output stream including title by artist from year
ostream& operator<<(ostream& out, Media& m){
  out << m.GetTitle() << " by " << m.GetArtist() << endl;
  return out;
}

//Overloaded Relational Operator (<)
//if passed media's year is less than first, return true else false
bool Media::operator<(const Media& m){
  if(m.GetYear() < GetYear())
    return true;
  return false;
}

