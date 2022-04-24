# Randomizing the string is the slowest thing of all
# The looping part the slowest of all

import random
import string

def test(size):
	print('entered the function')

	b = bytearray(size)
	print('Byte Array created')

	print('Radomizing started')
	# This is the slow process
	for i in range(size):
		b[i] = ord(random.choice(string.ascii_letters))
		# b[i] = ord('a')

	print('Radomizing ended')
	
	print('File Writing started')
	with open('test.txt', 'wb') as fh:
	    fh.write(b)
	
	print('File Writing Done')
	

if __name__ == '__main__':
    size = int(input("Enter size in bytes: "))
    test(size)
    print("file created")

