package io.philo.codingtest.ch_2__D_BFS._2__문제._2M_숌_666

fun main() {

    var i = readln().toInt()

    var simbol = 666

    while (true) {

        if (simbol.toString().contains("666")) i--

        if(i==0) break

        simbol++
    }

    println(simbol)
}