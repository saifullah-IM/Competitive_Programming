const tests = parseInt(readline());

for (var i = 0; i < tests; i++) {
    var word = readline();
    if (word.length > 10) {
        word = word[0] + (word.length - 2) + word[word.length - 1];
    }
    print(word);
}