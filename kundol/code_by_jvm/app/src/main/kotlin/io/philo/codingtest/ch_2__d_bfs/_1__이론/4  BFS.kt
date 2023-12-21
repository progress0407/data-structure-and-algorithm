package io.philo.codingtest.ch_2__d_bfs._1__이론

import java.util.LinkedList
import java.util.Queue

/**
 * 주의!
 *
 * queue.push(Int) 와 add(Int)는 다르다!
 *
 * push - 스택
 *
 * add - 큐
 */
fun main() {
//    `큐 연습`()
//    `큐 연습  2`()
    `BFS`()
}

private fun `큐 연습`() {
    val queue = LinkedList<Int>()
    queue.add(1)
    queue.add(2)
    queue.add(3)
//    queue.push(1)
//    queue.push(2)
//    queue.push(3)

//    println("queue.remove() = ${queue.remove()}")
//    println("queue.pop() = ${queue.pop()}")
//    println("queue.first() = ${queue.first()}")
    println("queue.poll() = ${queue.poll()}")
    println("queue = ${queue}")
}
private fun `큐 연습  2`() {
    val queue: Queue<Int> = LinkedList<Int>()
    queue.add(1)
    queue.add(2)
    queue.add(3)

    println("queue.remove() = ${queue.remove()}")
//    println("queue.pop() = ${queue.pop()}")
//    println("queue.first() = ${queue.first()}")
//    println("queue.poll() = ${queue.poll()}")

    println("queue = ${queue}")
}



private fun BFS() {
//    val adj = Array<MutableList<Int>>(10) { mutableListOf() }
    val m = 9
    val adj = Array<MutableList<Int>>(m + 1) { mutableListOf() }
    val vis = IntArray(m + 1)

    adj[1].addAll(listOf(2, 3, 4))
    adj[2].add(5)
    adj[3].addAll(listOf(6, 7))
    adj[4].add(8)
    adj[6].add(9)

    val root = 1

    val queue = LinkedList<Int>()
    queue.push(root)

    while (queue.isNotEmpty()) {
        val here = queue.poll()
        vis[here] = 1
        println("here = ${here}")
        for (there in adj[here]) {
            if(vis[there] == 1) continue
            queue.add(there)
        }
    }
}
