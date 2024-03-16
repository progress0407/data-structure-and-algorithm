from itertools import combinations
from copy import deepcopy
from math import fabs

N, M = map(int, input().split())
source_mapp = [list(map(int, input().split())) for _ in range(N)]
chi_source_list = []
home_list = []

for y in range(N):
    for x in range(N):
        dot = source_mapp[y][x]
        if dot == 2:
            chi_source_list.append((y, x))
            source_mapp[y][x] = 0  # 치킨 정보는 리스트에 보관함
        elif dot == 1:
            home_list.append((y, x))

chis_combination_list = list(combinations(chi_source_list, M))

city_chi_d_list=[]
for chis in chis_combination_list:
    # 도시의 치킨 거리
    city_chi_d = 0
    mapp = deepcopy(source_mapp)

    # 치킨 거리 리스트
    chi_d_list = []
    for hy, hx in home_list:
        chi_d = min([int(fabs(hy - cy)) + int(fabs(hx - cx)) for cy, cx in chis])
        chi_d_list.append(chi_d)
    city_chi_d = sum(chi_d_list)
    city_chi_d_list.append(city_chi_d)

# print(f'city_chi_d_list = {city_chi_d_list}')
# print(f'min of city_chi_d_list = {min(city_chi_d_list)}')
print(min(city_chi_d_list))
