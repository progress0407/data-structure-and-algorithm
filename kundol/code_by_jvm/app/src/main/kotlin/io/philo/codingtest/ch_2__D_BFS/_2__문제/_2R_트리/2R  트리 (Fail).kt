package io.philo.codingtest.ch_2__D_BFS._2__문제._2R_트리

/**
 * 2R 트리 (Fail)
 */

private var n = 0
private var root = -1
private var d = 0  // 지울 노드
private lateinit var nums: IntArray
private lateinit var graph: MutableList<MutableList<Int>>

fun main() {

    input()
    createGrpaht()
//    printGraph()

    if (handleException()) return

    dfs(root)

    println(cnt) // answer
}

private fun handleException(): Boolean {
    if (root == d) {
        println(0)
        return true
    }
    return false
}

private fun input() {
    n = readln().toInt()
    graph = MutableList(n) { mutableListOf() }
    nums = readln().split(" ").map { it.toInt() }.toIntArray()
    d = readln().toInt()
}

private fun createGrpaht() {
    for (i in nums.indices) {
        val num = nums[i]
        if (num == -1)
            root = i
        else
            graph[num].add(i)
    }
}

var cnt = 0


fun dfs(element: Int) {

    val children = graph[element]

    if (children.isEmpty()) cnt++

    for (child in children) {
        if (child == d) {
            continue
        }
        dfs(child)
    }
}

private fun printGraph() {
    for (i in graph.indices) {
        val ints = graph[i]
        print("$i: ")
        for (int in ints) {
            print("$int ")
        }
        println()
    }
}
