#!/usr/bin/python

# from apiclient.discovery import build
# from discovery import build
# from errors import HttpError
# import tools
# from tools import argparser
# import apiclient.discovery
# from apiclient.errors import HttpError
# from oauth2client.tools import argparser
import sys
# from math import *

def multiply(a,b):
	print "Will compute", a, "times", b

	print "TES python.";
    
	print "Result from python";

	return a * b;


# def GetYoutubeVideoList():
# # Set DEVELOPER_KEY to the API key value from the APIs & auth > Registered apps
# # tab of
# #   https://cloud.google.com/console
# # Please ensure that you have enabled the YouTube Data API for your project.
# 	DEVELOPER_KEY = "AIzaSyBsywKP4IoVsi8aZy9ImOyYK732KXbjWw0"
# 	YOUTUBE_API_SERVICE_NAME = "youtube"
# 	YOUTUBE_API_VERSION = "v3"

# def youtube_search(options):
# 	youtube = build(YOUTUBE_API_SERVICE_NAME, YOUTUBE_API_VERSION,
# 	developerKey=DEVELOPER_KEY)

# 	# Call the search.list method to retrieve results matching the specified
# 	# query term.
# 	search_response = youtube.search().list(
# 	q=options.q,
# 	part="id,snippet",
# 	maxResults=options.max_results
# 	).execute()

# 	videos = []
# 	channels = []
# 	playlists = []

# 	# Add each result to the appropriate list, and then display the lists of
# 	# matching videos, channels, and playlists.
# 	for search_result in search_response.get("items", []):
# 		if search_result["id"]["kind"] == "youtube#video":
# 	  		# print search_result
# 	  		print "=========================================="
# 	  		videos.append("%s" % search_result["snippet"]["title"])
# 	  		videos.append("%s" % search_result["snippet"]["thumbnails"]["default"]["url"])
# 	  		print "==========================================" 
# 	  # videos.append("%s %s" % ( search_result["snippet"]["title"]) )



# 	  # videos.append("%s (%s)" % (search_result["snippet"]["title"],
# 	  #                            search_result["id"]["videoId"]))
# 	# elif search_result["id"]["kind"] == "youtube#channel":
# 	#   channels.append("%s (%s)" % (search_result["snippet"]["title"],
# 	#                                search_result["id"]["channelId"]))
# 	# elif search_result["id"]["kind"] == "youtube#playlist":
# 	#   playlists.append("%s (%s)" % (search_result["snippet"]["title"],
# 	#                                 search_result["id"]["playlistId"]))

# 	print "Videos:\n", "\n".join(videos), "\n"

# 	return videos;
# 	# print "Channels:\n", "\n".join(channels), "\n"
# 	# print "Playlists:\n", "\n".join(playlists), "\n"



# def YoutubeSearch():
# 	argparser.add_argument("--q", help="Search term", default="Passenger")
# 	argparser.add_argument("--max-results", help="Max results", default=25)
# 	args = argparser.parse_args()

# 	try:
# 		youtube_search(args)
# 	except HttpError, e:
# 		print "An HTTP error %d occurred:\n%s" % (e.resp.status, e.content)
 
def StringTest():
	html = '<html>';
	html += '<head>';
	html += '<link href="css/bootstrap.min.css" rel="stylesheet">';
	html += '<link rel="stylesheet" type="text/css" href="style.css">';
	html += '</head>';
	html += '<body>';
	html += '<div class="navbar navbar-default">';
	html += '<div class="navbar-header">';
	html += '<a class="navbar-brand" href="#">Playlist</a>';
	html += '</div>';
	html += '<ul class="nav navbar-nav">';
  	html += '<li><a href="#">Home</a></li>';
  	html += '<li><a href="#">News</a></li>';
  	html += '<li><a href="#">Contact</a></li>';
  	html += '<li><a href="#">About</a></li>';
	html += '<ul>';
	html += '</div>';
	html += '<h1>Python html</h1>';
	html += '<h2>test</h2>';
	html += '<h3>test3</h3>';
	html += '<h4>test4</h4>';

	html += '<div class="list-group media">';
	
	# html += '<li class="media list-group-item-text">'
	# html += '<div class="media-left">'
	# html += '<a href="#">'
	# html += '<img class="media-object" src="..." alt="...">'
	# html += '</a>'
	# html += '</div>'
	# html += '<div class="media-body">'
	# html += '<h4 class="media-heading">Media heading</h4>'
	# html += '...'
	# html += '</div>'
	# html += '</li>'


	# html += '<li class="media">'
	# html += '<div class="media-left">'
	# html += '<a href="#">'
	# html += '<img class="media-object" src="..." alt="...">'
	# html += '</a>'
	# html += '</div>'
	# html += '<div class="media-body">'
	# html += '<h4 class="media-heading">Media heading</h4>'
	# html += '...'
	# html += '</div>'
	# html += '</li>'
	# html += '<a href="#" class="list-group-item">';
	# html += '<h4 class="list-group-item-heading">List group item heading</h4>';
	# html += '<p class="list-group-item-text">...</p>';
	# html += '</a>';


	#---------------------------------------------------------------------
	html += '<a href="#" class="list-group-item">';
	
	html += '<div class="media-left media-middle">'
	html += '<img class="media-object" src="..." alt="...">'
	html += '</div>'

	html += '<div class="media-body">'
	html += '<h4 class="list-group-item-heading">List group item heading</h4>';
	html += '<p class="list-group-item-text">...</p>';
	html += '</div>'
	
	html += '</a>';
	#---------------------------------------------------------------------

	html += '<a href="#" class="list-group-item">';
	
	html += '<div class="media-left media-middle">'
	html += '<img class="media-object" height="64" width="64" src="https://i.ytimg.com/vi/RBumgq5yVrA/default.jpg" alt="...">'
	html += '</div>'

	html += '<div class="media-body">'

	html += '<h4 class="list-group-item-heading">Passenger - Let Her Go [Official Video]</h4>';
	html += '<p class="list-group-item-text">The official video for "Let Her Go", as featured in the Budweiser Superbowl 2014 commercial. Directed and Produced by Dave Jansen. Amazing work Dave ...</p>';

	html += '</div>'
	
	html += '</a>';
	#---------------------------------------------------------------------

	html += '</div>';

	html += '</body>';
	html += '</html>';


	# print sys.path;

	# YoutubeSearch();
	return html;

def TestFct():
	print "FUCK";