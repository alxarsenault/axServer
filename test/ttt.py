#!/usr/bin/python

# from apiclient.discovery import build
# from discovery import build
# from errors import HttpError

from apiclient.discovery import build
from apiclient.errors import HttpError
from oauth2client.tools import argparser

import sys

def multiply(a,b):
	print "Will compute", a, "times", b

	print "TES python.";
    
	print "Result from python";

	return a * b;

# def GetYoutubeVideoList():
# Set DEVELOPER_KEY to the API key value from the APIs & auth > Registered apps
# tab of
# https://cloud.google.com/console
# Please ensure that you have enabled the YouTube Data API for your project.
DEVELOPER_KEY = "AIzaSyBsywKP4IoVsi8aZy9ImOyYK732KXbjWw0"
YOUTUBE_API_SERVICE_NAME = "youtube"
YOUTUBE_API_VERSION = "v3"

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

	videos = []
	channels = []
	playlists = []

	# Add each result to the appropriate list, and then display the lists of
	# matching videos, channels, and playlists.
	for search_result in search_response.get("items", []):
		if search_result["id"]["kind"] == "youtube#video":
	  		# print search_result
	  		#print "=========================================="
	  		videos.append("%s" % search_result["snippet"]["title"])
	  		videos.append("%s" % search_result["snippet"]["thumbnails"]["default"]["url"])
	  		# print "==========================================" 

	print "Videos:\n", "\n".join(videos), "\n"

	return videos;

def YoutubeSearch():
	argparser.add_argument("--q", help="Search term", default="Passenger")
	argparser.add_argument("--max-results", help="Max results", default=25)
	args = argparser.parse_args()

	try:
		youtube_search(args)
	except HttpError, e:
		print "An HTTP error %d occurred:\n%s" % (e.resp.status, e.content)
 
def StringTest():
	html = '<html>';
	html += '<body>';
	html += '<h1>Python html</h1>'
	html += '<h2>test</h2>'
	html += '<h3>test3</h3>'
	html += '<h4>test4</h4>'
	html += '</body>';
	html += '</html>';

	videos = YoutubeSearch();
	return html;

def TestFct():
	print "FUCK";