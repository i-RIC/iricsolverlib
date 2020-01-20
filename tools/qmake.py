import devtool as dev
import subprocess
import os

def qmake(path):
  cwd = os.getcwd()
  os.chdir(path)
  try:
    subprocess.check_output('qmake')
    print('qmake executed for ' + path)
  except subprocess.CalledProcessError:
    pass
  os.chdir(cwd)

print('executing qmake ...')
dev.recursiveExecFolder("..", qmake)
