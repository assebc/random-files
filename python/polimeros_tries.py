from os import system, name
import statistics

polimero = input("Introduza polimero: ")
i = input("Introduza o numero de ensaios realizados: ")


accum = accum2 = accum3 = accum4 = 0

while i>0:
    tm = input("Introduza a temperatura em, graus Celsius, de transicao vitrea do polimero: ")
    tm_list[i] = tm
    i -= 1 # decrescenta ao longo do ciclo

while i>0:
    tg = input("Introduza a temperatura de fusao, em graus Celsius, do polimero: ")
    tg_list[i] = tg
    i -= 1 # decrescenta ao longo do ciclo

while i>0:
    ts = input("Introduza a temperatura de fusao, em graus Celsius, do polimero: ")
    ts_list[i] = ts
    i -= 1 # decrescenta ao longo do ciclo

while i>0:
    p = input("Introduza a pressao necessária em toneladas para moldar o polimero: ")
    p_list[i] = p
    i -= 1 # decrescenta ao longo do ciclo

while i>0:
    accum += tm_list[i]
    accum2 += tg_list[i]
    accum3 += ts_list[i]
    accum4 += p_list[i]
    i-= 1

# medias
media_tm = accum/i
media_tg = accum2/i
media_ts = accum3/i
media_p = accum4/i

# desvios padrao

dp_tm = statistics.pvariance(tm_list)
dp_tg = statistics.pvariance(tg_list)
dp_ts = statistics.pvariance(ts_list)
dp_p = statistics.pvariance(p_list)

clear()

print("medias\n")
print(media_tm)
print(media_tg)
print(media_ts)
print(media_p)

print("desvios padrao\n")
print(dp_tm)
print(dp_tg)
print(dp_ts)
print(dp_p)