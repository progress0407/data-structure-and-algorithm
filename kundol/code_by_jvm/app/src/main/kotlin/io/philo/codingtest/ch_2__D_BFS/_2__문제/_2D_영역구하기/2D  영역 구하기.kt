package io.philo.codingtest.ch_2__D_BFS._2__문제._2D_영역구하기

private lateinit var mapp: Array<IntArray>
private lateinit var vis: Array<IntArray>
private val dy = intArrayOf(1, 0, -1, 0)
private val dx = intArrayOf(0, 1, 0, -1)

private var m: Int = 0 // 세로
private var n: Int = 0 // 가로
private var k: Int = 0 // 가리는 영역 갯수

private val areas: MutableList<Int> = mutableListOf()

/**
 * public case: pass
 * private case: pass
 */
fun main() {
    val inp = readln().split(" ").map { it.toInt() }
    m = inp[0]
    n = inp[1]
    k = inp[2]
    mapp = Array(m) { IntArray(n) }
    vis = Array(m) { IntArray(n) }

    repeat(k) {
        // 왼쪽 아래(x, y), 오른쪽 아래(x, y)
        val (lx, ly, rx, ry) = readln().split(" ").map { it.toInt() }

        for (y in ly..ry - 1) { // 중요!! 좌표와 크기의 차이 고려!
            for (x in lx..rx - 1) {
                mapp[y][x] = 1
            }
        }
    }

    for (y in 0..m - 1) {
        for (x in 0..n - 1) {
            if (mapp[y][x] == 0 && vis[y][x] == 0) {
                val area = dfs(y, x)
                areas.add(area)
            }
        }
    }

    println(areas.sorted().joinToString(" "))
}

private fun dfs(y: Int, x: Int): Int {

    var area = 1
    vis[y][x] = 1

    for (i in 0..3) {
        val ny = y + dy[i]
        val nx = x + dx[i]

        if (ny in 0..m - 1 &&
            nx in 0..n - 1 &&
            mapp[ny][nx] == 0 &&
            vis[ny][nx] == 0) {

            area += dfs(ny, nx)
        }
    }
    return area
}
