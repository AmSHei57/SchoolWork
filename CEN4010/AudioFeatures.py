import spotipy
from spotipy.oauth2 import SpotifyClientCredentials
import spotipy.util as util

cid ="3f0e293f3d364d33911339833af8a563" 
secret = "bdf5575475844f67b956986517f76e5e"
username = "aminspects"
redirect_url = "http://localhost:8888/callback"
client_credentials_manager = SpotifyClientCredentials(client_id=cid, client_secret=secret) 
sp = spotipy.Spotify(client_credentials_manager=client_credentials_manager)
scope = 'user-library-read playlist-read-private'

def Authentication():
    token = util.prompt_for_user_token(username,
    scope,
    cid,
    secret,
    redirect_url)
    if token:
        sp = spotipy.Spotify(auth=token)
    else:
        print("Can't get token for", username)
        
def AudioFeatures():
    playlist = sp.user_playlist("aminspects", "3dWSnJsb7ZkCYbq62WjyNQ")
    tracks = playlist["tracks"]
    songs = tracks["items"] 
    while tracks['next']:
        tracks = sp.next(tracks)
        for item in tracks["items"]:
            songs.append(item)
    ids = [] 
    for i in range(len(songs)- 500):
        ids.append(songs[i]['track']['id'])

    features = []
    for i in range(0,len(ids),50):
        audio_features = sp.audio_features(ids[i:i+50])
        for track in audio_features:
            features.append(track)
            features[-1]['target'] = 1
    
def main():
    Authentication()
    AudioFeatures()

    main()