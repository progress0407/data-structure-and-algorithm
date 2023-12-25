package io.philo.codingtest.ch_2__D_BFS._1__이론

import java.util.LinkedList

private var dy = intArrayOf(1, 0, -1, 0)
private var dx = intArrayOf(0, 1, 0, -1)

private lateinit var mapp: Array<IntArray>
private lateinit var vis: Array<IntArray>

/**
 * 맵 크기  세로 가로
 *
 * 처음 위치 y x
 *
 * 목표 위치 y x
 */

private var my: Int = 0
private var mx: Int = 0

private var sy: Int = 0
private var sx: Int = 0

private var ey: Int = 0
private var ex: Int = 0

fun main() {

    val inp1 = readln().split(" ").map { it.toInt() }
    my = inp1[0]; mx = inp1[1]

    val inp2 = readln().split(" ").map { it.toInt() }
    sy = inp2[0]; sx = inp2[1]

    val inp3 = readln().split(" ").map { it.toInt() }
    ey = inp3[0]; ex = inp3[1]

    mapp = Array(my) { IntArray(mx) }
    vis = Array(my) { IntArray(mx) }

    repeat(my) { y ->
        mapp[y] = readln().split(" ").map { it.toInt() }.toIntArray()
    }

    val queue = LinkedList<Pair<Int, Int>>()
    queue.add(Pair(sy, sx))
    vis[sy][sx] = 1

    while (queue.isNotEmpty()) {

        val here = queue.poll()

        for (i in 0..3) {
            val y = here.first
            val x = here.second

            val ny = y + dy[i]
            val nx = x + dx[i]

            if (ny in 0..my - 1 &&
                nx in 0..mx - 1 &&
                mapp[ny][nx] == 1 &&
                vis[ny][nx] == 0) {

                vis[ny][nx] = vis[y][x] + 1
                queue.add(here)
            }
        }
    }

    println("${vis[ey][ex]}")
    vis.forEach { println(it.contentToString()) }
}
