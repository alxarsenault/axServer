#!/usr/bin/python

from apiclient.discovery import build
from apiclient.errors import HttpError
from oauth2client.tools import argparser
import sys
# from math import *

DEVELOPER_KEY = "AIzaSyBsywKP4IoVsi8aZy9ImOyYK732KXbjWw0"
YOUTUBE_API_SERVICE_NAME = "youtube"
YOUTUBE_API_VERSION = "v3"

def multiply(a,b):
	print "Will compute", a, "times", b

	print "TES python.";
    
	print "Result from python";

	return a * b;

def youtube_search(options):
	youtube = build(YOUTUBE_API_SERVICE_NAME, YOUTUBE_API_VERSION,
	developerKey=DEVELOPER_KEY)

	# Call the search.list method to retrieve results matching the specified
	# query term.
	search_response = youtube.search().list(
	q=options.q,
	part="id,snippet",
	maxResults=options.max_results
	).execute()

	return search_response;

def YoutubeSearch(search_str = "Passenger"):
	argparser.add_argument("--q", help="Search term", default=search_str)
	argparser.add_argument("--max-results", help="Max results", default=25)
	args = argparser.parse_args()

	try:
		return youtube_search(args)
	except HttpError, e:
		print "An HTTP error %d occurred:\n%s" % (e.resp.status, e.content)
 

def AppendVideoToHtml(video_name, video_img_addr, description):
	html = '<a href="#" class="list-group-item">';
	
	html += '<div class="media-left media-middle">'
	html += '<img class="media-object" height="64" width="64" src="' + video_img_addr + '" alt="...">'
	html += '</div>'

	html += '<div class="media-body">'

	html += '<h4 class="list-group-item-heading">' + video_name +'</h4>';
	html += '<p class="list-group-item-text">' + description + '</p>';

	html += '</div>'
	
	html += '</a>';

	return html;

def StringTest(search_str):

	print "SEARCH STRING : " + search_str;

	# html = '<html>';
	# html += '<head>';
	# html += '<link href="css/bootstrap.min.css" rel="stylesheet">';
	# html += '<link rel="stylesheet" type="text/css" href="style.css">';
	# html += '</head>';
	# html += '<body>';
	# html += '<div class="navbar navbar-default">';
	# html += '<div class="navbar-header">';
	# html += '<a class="navbar-brand" href="#">Playlist</a>';
	# html += '</div>';
	# html += '<ul class="nav navbar-nav">';
 #  	html += '<li><a href="#">Add</a></li>';
 #  	# html += '<li><a href="#">News</a></li>';
 #  	# html += '<li><a href="#">Contact</a></li>';
 #  	# html += '<li><a href="#">About</a></li>';
	# html += '<ul>';
	# html += '</div>';
	# html += '<h1>Python html</h1>';
	# html += '<h2>test</h2>';
	# html += '<h3>test3</h3>';
	# html += '<h4>test4</h4>';

	# html = '<form action="search">'
	# html += '<fieldset>'
	# html += '<legend>Personal information:</legend>'
	# html += 'First name:<br>'
	# html += '<input type="text" name="search_video" value="Mickey">'
	# html += '<br>'
	# # html += 'Last name:<br>'
	# # html += '<input type="text" name="lastname" value="Mouse">'
	# html += '<br><br>'
	# html += '<input type="submit" value="Submit"></fieldset>'
	# html += '</form>'

	# html +='<div class="list-group media">';
	

	# if(search_str != "")

	search_response = YoutubeSearch(search_str);

	for search_result in search_response.get("items", []):
		if search_result["id"]["kind"] == "youtube#video":
	  		title = search_result["snippet"]["title"];
	  		img = search_result["snippet"]["thumbnails"]["default"]["url"];
	  		description = search_result["snippet"]["description"];
	  		html += AppendVideoToHtml(title, img, description);

	html += '</div>';

	# html += '</body>';
	# html += '</html>';

	return html;

def SearchPage(search_str):
	print "SEARCH STRING : " + search_str;

	# html = '<html>';
	# html += '<head>';
	# html += '<link href="css/bootstrap.min.css" rel="stylesheet">';
	# html += '<link rel="stylesheet" type="text/css" href="style.css">';
	# html += '</head>';
	# html += '<body>';
	# html += '<div class="navbar navbar-default">';
	# html += '<div class="navbar-header">';
	# html += '<a class="navbar-brand" href="#">Playlist</a>';
	# html += '</div>';
	# html += '<ul class="nav navbar-nav">';
 #  	html += '<li><a href="#">Add</a></li>';
 #  	# html += '<li><a href="#">News</a></li>';
 #  	# html += '<li><a href="#">Contact</a></li>';
 #  	# html += '<li><a href="#">About</a></li>';
	# html += '<ul>';
	# html += '</div>';
	# html += '<h1>Python html</h1>';
	# html += '<h2>test</h2>';
	# html += '<h3>test3</h3>';
	# html += '<h4>test4</h4>';

	# html = '<form action="search">'
	# html += '<fieldset>'
	# html += '<legend>Personal information:</legend>'
	# html += 'First name:<br>'
	# html += '<input type="text" name="search_video" value="Mickey">'
	# html += '<br>'
	# # html += 'Last name:<br>'
	# # html += '<input type="text" name="lastname" value="Mouse">'
	# html += '<br><br>'
	# html += '<input type="submit" value="Submit"></fieldset>'
	# html += '</form>'

	html ='<div class="list-group media">';
	
	search_response = YoutubeSearch(search_str);

	for search_result in search_response.get("items", []):
		if search_result["id"]["kind"] == "youtube#video":
	  		title = search_result["snippet"]["title"];
	  		img = search_result["snippet"]["thumbnails"]["default"]["url"];
	  		description = search_result["snippet"]["description"];
	  		html += AppendVideoToHtml(title, img, description);

	html += '</div>';

	# html += '</body>';
	# html += '</html>';

	return html;










	# html = '<html>';
	# html += '<head>';
	# html += '<link href="css/bootstrap.min.css" rel="stylesheet">';
	# html += '<link rel="stylesheet" type="text/css" href="style.css">';
	# html += '</head>';
	# html += '<body>';
	# html += '<div class="navbar navbar-default">';
	# html += '<div class="navbar-header">';
	# html += '<a class="navbar-brand" href="#">Playlist</a>';
	# html += '</div>';
	# html += '<ul class="nav navbar-nav">';
 #  	html += '<li><a href="#">Add</a></li>';
	# html += '<ul>';
	# html += '</div>';

	# html += '<form action="search">'
	# html += '<fieldset>'
	# html += '<legend>Personal information:</legend>'
	# html += 'First name:<br>'
	# html += '<input type="text" name="search_video" value="Mickey">'
	# html += '<br>'
	# # html += 'Last name:<br>'
	# # html += '<input type="text" name="lastname" value="Mouse">'
	# html += '<br><br>'
	# html += '<input type="submit" value="Submit"></fieldset>'
	# html += '</form>'


	# html += '</body>';
	# html += '</html>';

	# return html;