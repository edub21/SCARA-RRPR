from setuptools import find_packages
from setuptools import setup

setup(
    name='avig_msg',
    version='0.0.0',
    packages=find_packages(
        include=('avig_msg', 'avig_msg.*')),
)
