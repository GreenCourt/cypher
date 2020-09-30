import numpy as np
import matplotlib.pyplot as plt
import itertools

text= [[0b11111110, 0b00000001, 0b00000000, 0b00000001],
       [0b11111110, 0b11111110, 0b11111110, 0b00000000],
       [0b11111110, 0b11111111, 0b11111110, 0b00000000],
       [0b00000000, 0b11111111, 0b00000001, 0b00000001],]

print(chr(int(''.join([str(i&0b1) for i in bytes(itertools.chain.from_iterable(text))[:8]]),2)))
print(chr(int(''.join([str(i&0b1) for i in bytes(itertools.chain.from_iterable(text))[8:]]),2)))

img = np.array(text)
plt.imshow(img)
plt.show()
