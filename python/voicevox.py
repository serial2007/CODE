#!/usr/bin/python3

import requests
import json
import sys
import os

def gen_voice(text, speaker=1, filename="output.wav"):
	query_payload = {'text': text, 'speaker': speaker}
	query_response = requests.post(f'http://localhost:50021/audio_query', params=query_payload)

	if query_response.status_code != 200:
		print(f"Error in audio_query: {query_response.text}")
		return

	query = query_response.json()
	synthesis_payload = {'speaker': speaker}
	synthesis_response = requests.post(f'http://localhost:50021/synthesis', params=synthesis_payload, json=query)

	if synthesis_response.status_code == 200:
		with open(filename, 'wb') as f:
			f.write(synthesis_response.content)
		print(f"音声が {filename} に保存されました。")
	else:
		print(f"Error in synthesis: {synthesis_response.text}")

def wine_path(linux_path):
	if linux_path.startswith('/'):
		return 'Z:' + linux_path.replace('/', '\\')
	else:
		return linux_path

def linux_path(gal_id, wine_path):
	if wine_path.startswith('Z:') or wine_path.startswith('z:'):
		linux_path = wine_path[2:].replace('\\', '/')
		return '/' + linux_path
	else:
		linux_path = wine_path[2:].replace('\\', '/')
		if gal_id == '0':
			wineprefix = os.environ.get('WINEPREFIX')
			if not wineprefix:
				wineprefix = '~/.wine/'
			return wineprefix + 'drive_c/' + wine_path
		else:
			return '~/.steam/steam/steamapps/compatdata/' + gal_id + '/pfx/drive_c/' + wine_path


if __name__ == "__main__":
	with open("/home/chen/code/python/output.txt", "w") as file:
		file.write("\n".join(sys.argv))


	text = sys.argv[1]
	if not text:
		text = "こんにちは、VOICEVOXでテキストを音声に変換しています。"
	if len(sys.argv) > 3:
		gal_id = sys.argv[3]
	else:
		gal_id = '0'
	filename = linux_path(gal_id, sys.argv[2])
	
	gen_voice(text, speaker=1, filename=filename)

