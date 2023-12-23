package io.philo.codingtest.ch_2__d_bfs._2__문제._2J_기상캐스터

var mapp = mutableListOf<String>()
private lateinit var pointMap: Array<IntArray>

fun main() {
    val (h, w) = readln().split(" ").map { it.toInt() }
    pointMap = Array(h) { IntArray(w) }

    repeat(h) {
        val str = readln()
        mapp.add(str)
    }

    for (r in mapp.indices) {
        val row = mapp[r]
        for (c in row.indices) {

            if(row[c] == 'c') {
                pointMap[r][c] = 0
            } else if (row[c] == '.') {
                // 구름 위치 찾기
                var cloudIndex = -1
                for (k in c - 1 downTo 0) {
                    if (row[k] == 'c') {
                        cloudIndex = k
                        break
                    }
                }
                if (cloudIndex != -1) {
                    val point = c - cloudIndex
                    pointMap[r][c] = point
                } else {
                    pointMap[r][c] = -1
                }
            }
        }
    }

    pointMap.forEach {
        println(it.joinToString(" "))
    }
}