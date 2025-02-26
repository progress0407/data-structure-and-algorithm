package io.philo.codingtest.ch_2__D_BFS._2__문제._2A_미로

import java.util.*

private var my: Int = 0
private var mx: Int = 0

private lateinit var mapp: Array<IntArray>
private lateinit var vis: Array<IntArray>

private val dy = intArrayOf(1, 0, -1, 0)
private val dx = intArrayOf(0, 1, 0, -1)

private val queue = LinkedList<Pair<Int, Int>>()

fun main() {
    val inp = readln().split(" ").map { it.toInt() }
    my = inp[0]
    mx = inp[1]
    mapp = Array(my) { IntArray(mx) }
    vis = Array(my) { IntArray(mx) }

    repeat(my) { y ->
        val inpXLine = readln()
        mapp[y] = inpXLine.split("").filter { it.isNotEmpty() }.map { it.toInt() }.toIntArray()
    }

    queue.add(Pair(0, 0))
    vis[0][0] = 1

    while (queue.isNotEmpty()) {

        val here = queue.poll()
//        println("here = ${here}")

        for (i in 0..3) {
            val y = here.first
            val x = here.second

            val ny = y + dy[i]
            val nx = x + dx[i]

            if (ny in 0..my - 1 && nx in 0..mx - 1) {
                if (mapp[ny][nx] == 1) {
                    if (vis[ny][nx] == 0) {
                        queue.add(Pair(ny, nx))
                        vis[ny][nx] = vis[y][x] + 1
                    }
                }
            }
        }
    }

    println(vis[my - 1][mx - 1])

//    vis.forEach { println(it.contentToString()) }
}