import subprocess

cwd = 'C:/Users'
args = ['start', '/wait', 'cmd']

subprocess.call(args, cwd=cwd, shell=True)
