#!/usr/bin/env python

from distutils.core import setup, Extension


module1 = Extension('imghash',
		    include_dirs = ['../include','/usr/include/ImageMagick'],
		    libraries = ['imghash'],
                    sources = ['imghash_wrap.cpp','../lib/imghash_c.cpp'])

setup(name='imghash',
      version='0.1.1',
      description='Image hashing library',
      author='Roman Grebennikov',
      author_email='grebennikov.roman@gmail.com',
      url='https://github.com/shuttie/libimghash',
      ext_modules=[module1]
     )
