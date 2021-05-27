onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib sine_mid_opt

do {wave.do}

view wave
view structure
view signals

do {sine_mid.udo}

run -all

quit -force
