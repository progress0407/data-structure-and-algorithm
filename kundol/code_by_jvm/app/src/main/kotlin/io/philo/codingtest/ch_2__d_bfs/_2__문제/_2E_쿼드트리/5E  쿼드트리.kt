package io.philo.codingtest.ch_2__d_bfs._2__문제._2E_쿼드트리

/**
 *
 */
private lateinit var mapp: Array<IntArray>
private lateinit var vis: Array<IntArray>

fun main() {
    val n = readln().toInt()
    mapp = Array(n) { IntArray(n) }
    vis = Array(n) { IntArray(n) }

    repeat(n) { index ->
        mapp[index] = readln().map { it.toString().toInt() }.toIntArray()
    }

    val result = go(n, 0, 0)
    println(result)
}

/**
 * size
 *
 * sy: start y
 *
 * sx: start x
 */
private fun go(size: Int, sy: Int, sx: Int): String {

    val pivotNum = mapp[sy][sx]

    if (size == 1) {
        return pivotNum.toString()
    }

    for (y in sy..sy + size - 1) {
        for (x in sx..sx + size - 1) {
            if (mapp[y][x] != pivotNum) {

                val newSize = size / 2

                return "(" +
                        go(newSize, sy, sx) +
                        go(newSize, sy, sx + newSize) +
                        go(newSize, sy + newSize, sx) +
                        go(newSize, sy + newSize, sx + newSize) +
                        ")"
            }
        }
    }

    return pivotNum.toString()
}