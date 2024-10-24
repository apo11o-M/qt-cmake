import os
import numpy as np
from scipy import signal as scisig, io as scio
from matplotlib import pyplot as plt

THIS_DIR = os.path.dirname(os.path.abspath(__file__))

# config
num_ffts = 20
Fs = 10e6
NFFT = 2**14
noise_pow = -70
BW = 1000e3
fn = os.path.join(THIS_DIR, f'ffts_NFFT={NFFT:d}_N={num_ffts:d}.32f')

# calculate the signal peak bin centers
binsize = Fs / NFFT
print(f'binsize: {binsize:.2f} Hz')
center0 = int(BW / (2 * binsize))
centers = np.linspace(center0, NFFT - center0, num_ffts)
print(centers)
# generate quadratic hump on [-BW/2, BW/2]
sigma_noise = 10.0 ** (noise_pow / 20) / np.sqrt(2) # noise std [linear]
noise_pow_linear = 10.0 ** (noise_pow / 20)
p = np.polyfit(x=[-center0, 0, center0], y = [0, 1, 0], deg=2)
n = np.arange(NFFT)

# clear the file if the data exists here
os.remove(fn) if os.path.exists(fn) else None

# loop over and generate FFTs
plt.figure()
print(len(centers))
for i, cen, in enumerate(centers):
    # generate noise
    noise = sigma_noise * (np.random.randn(NFFT) + 1j * np.random.randn(NFFT))
    X = np.fft.fft(noise, norm='ortho')
    
    # generate signal hump
    keep = abs(n - cen) < center0
    S = np.polyval(p, n - cen) * keep
    X += S  # add to noise
    
    # take abs, cast to float
    Z = abs(X).astype(np.float32)
    
    # write to file
    with open(fn, "ab+") as f:
        f.write(abs(Z))
        
    # plot
    plt.plot(10 * np.log10(abs(X)))
    
plt.grid()
plt.savefig(os.path.join(THIS_DIR, 'ffts.png'))
plt.show()
