import spotipy
from spotipy.oauth2 import SpotifyClientCredentials
import spotipy.util as util

cid ="3f0e293f3d364d33911339833af8a563" #Client id from Developer dashboard
secret = "bdf5575475844f67b956986517f76e5e" #Client secret from Developer dashboard
uname = "zachary" #Client username, used for reference 
r_url = "http://localhost:8888/callback" #Redirects to specified url to confirm login

def Authentication(client_id,client_secret,username,redirect_url):
    
    client_credentials = SpotifyClientCredentials(client_id, client_secret) #Allows for server-to-server authentication
    sp = spotipy.Spotify(client_credentials)
    
    scope = 'user-library-read playlist-read-private' #Defines what the application will do, more from https://developer.spotify.com/documentation/general/guides/scopes/
    token = util.prompt_for_user_token( #Used to authorize user
    username,
    scope,
    client_id,
    client_secret,
    redirect_url)

    if token: #checks and assigns the token to sp                          
        sp = spotipy.Spotify(token)
        print("Got token for", username)
        return sp
    else:
        print("Can't get token for", username)


def main():
    Authentication(cid,secret,uname,r_url)

main()