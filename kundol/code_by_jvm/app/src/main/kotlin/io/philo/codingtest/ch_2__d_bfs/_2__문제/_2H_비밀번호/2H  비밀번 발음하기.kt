package io.philo.codingtest.ch_2__d_bfs._2__문제._2H_비밀번호

/**
 * 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
 *
 * 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
 *
 * 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
 */
private val vowels = arrayOf("a", "e", "i", "o", "u")

fun main() {

    while (true) {
        val input = readln()
        if (input == "end") break

        if (isValid1(input) && isValid2(input) && isValid3(input)) {
//        if (isValid3(input)) {
            println("<$input> is acceptable.")
        } else {
            println("<$input> is not acceptable.")
        }
    }
}

/**
 * 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
 */
private fun isValid1(str: String): Boolean {

    return vowels.any { str.contains(it) }
}

/**
 * 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
 */
private fun isValid2(str: String): Boolean {

    var cnt = 1
    var lastCategory = 0 // 0 모음, 1 자음

    // 처음 값
    if (vowels.contains(str.first().toString())) {
        lastCategory = 0
    } else {
        lastCategory = 1
    }

    for (i in str.indices) {
        if (i == 0) continue

        val target = str[i].toString()

        // 모음
        if (vowels.contains(target)) {
            // 이전것도 모음이면
            if (lastCategory == 0) cnt++
            // 아니면 초기화
            else cnt = 1
            lastCategory = 0
        } else { // 자음
            if (lastCategory == 1) cnt++
            else cnt = 1
            lastCategory = 1
        }
        if (cnt == 3) return false
    }
    return true
}
/**
 * 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
 */
private fun isValid3(str: String): Boolean {

    var lastCh = str[0]
    for (i in str.indices) {
        if(i==0) continue
        val ch = str[i]
        if (listOf("e", "o").contains(ch.toString())) {
            continue
        } else {
            if(lastCh == ch) return false
        }
        lastCh = ch
    }
    return true
}