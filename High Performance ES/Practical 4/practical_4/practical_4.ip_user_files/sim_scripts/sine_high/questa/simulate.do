onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib sine_high_opt

do {wave.do}

view wave
view structure
view signals

do {sine_high.udo}

run -all

quit -force
