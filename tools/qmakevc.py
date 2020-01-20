import devtool as dev
import subprocess
import os

def qmakevc(path):
  # print(path)
  cwd = os.getcwd()
  os.chdir(path)
  try:
    subprocess.check_output('qmake -tp vc')
    print('qmake executed for ' + path)
  except subprocess.CalledProcessError:
    pass
  os.chdir(cwd)

print('executing qmake -tp vc...')
dev.recursiveExecFolder("..", qmakevc)
