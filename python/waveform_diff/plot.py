import numpy as np
from matplotlib import pyplot as plt
from scipy import fftpack

w0 = np.loadtxt("wave1.csv", delimiter=",", skiprows=1)
w1 = np.loadtxt("wave2.csv", delimiter=",", skiprows=1)

'''
python - find time shift between two similar waveforms - Stack Overflow
http://stackoverflow.com/questions/4688715/find-time-shift-between-two-similar-waveforms
'''

A = fftpack.fft(w0[:, 1])
B = fftpack.fft(w1[:, 1])
Ar = -A.conjugate()
Br = -B.conjugate()
d0 = np.argmax(np.abs(fftpack.ifft(Ar * B)))
d1 = np.argmax(np.abs(fftpack.ifft(A * Br)))

print("Phase Difference")
print((d0, d1))

plt.title("Waveforms")
plt.plot(w0[:, 2], w0[:, 1], 'r', label="wave1.csv")
plt.plot(w1[:, 2], w1[:, 1], 'g', label="wave2.csv")
plt.legend()
plt.xlabel('Time(NL3)')
plt.ylabel('Voltage(NL3)')
plt.show()
