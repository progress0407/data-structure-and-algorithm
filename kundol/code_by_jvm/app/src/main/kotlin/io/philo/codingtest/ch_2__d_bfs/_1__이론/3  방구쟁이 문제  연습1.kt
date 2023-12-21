package io.philo.codingtest.ch_2__d_bfs._1__이론

/**
 * 자기 친구를 방구쟁이로 만든 희대의 문제 ...
 *
 * 종화는 21세기 유명한 방구쟁이다.
 *
 * 종화는 방구를 낄 때 "이러다... 다 죽어!!" 를 외치며 방구를 뀌는데 이렇게 방귀를 뀌었을 때
 *
 * 방귀는 상하좌우 네방향으로 뻗어나가며 종화와 연결된 "육지"는 모두 다 오염된다.
 *
 * "바다"로는 방구가 갈 수 없다.
 *
 * 맵이 주어졌을 때 종화가 "이러다... 다 죽어!!"를 "최소한" 몇 번외쳐야 모든 육지를 오염시킬 수 있는지 말해보자.
 *
 * 1은 육지며 0은 바다를 가리킨다.
 */

private var dy = intArrayOf(1, 0, -1, 0)
private var dx = intArrayOf(0, 1, 0, -1)

private lateinit var mapp: Array<IntArray>
private lateinit var vis: Array<IntArray>

private var my: Int = 0
private var mx: Int = 0

fun main() {

    val inp = readln().split(" ").map { it.toInt() }
    my = inp[0]
    mx = inp[1]
    mapp = Array(my) { IntArray(mx) }
    vis = Array(my) { IntArray(mx) }

    repeat(my) { y ->
        mapp[y] = readln().split(" ").map { it.toInt() }.toIntArray()
    }

    mapp.forEach { println(it.contentToString()) }

/*
    var cnt = 0
    mapp.forEachIndexed { y, mappRow ->
        mappRow.forEachIndexed { x, mappVal ->
            if (mappVal == 1 && vis[y][x] == 0) {

            }
        }
    }
*/

    var cnt = 0
    for (y in 0..my - 1) {
        for (x in 0..mx - 1) {
            if (mapp[y][x] == 1 && vis[y][x] == 0) {
                cnt++
                visit(y, x)
            }
        }
    }
}

private fun visit(y: Int, x: Int) {
    vis[y][x] = 1
    for (i in 0..3) {
        val ny = y + dy[i]
        val nx = x + dx[i]
        if (ny in 0..my - 1 && nx in 0..mx - 1 && vis[ny][nx] == 0 && mapp[y][x] == 1) {
            visit(ny, nx)
        }
    }
}