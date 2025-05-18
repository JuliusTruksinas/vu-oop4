# Word and URL Frequency Analyzer

This C++ program analyzes a given text file (`text.txt`) to count word frequencies, detect URLs, and track where each word appears within the text. The results are saved into three separate output files.

## How to Run

1. Make sure `text.txt` exists in the project folder with your desired text.
2. Compile and run the program by executing the following commands: `make` and `./main`

## How It Works

- **`cleanWord()`**: Removes punctuation and lowercases the word.
- **`isURL()`**: Uses a regex to detect full or short-form URLs like `https://...`, `www...`, or `domain.lt`.
- Uses a `map<string, pair<int, set<int>>>`:
  - First: word count
  - Second: set of unique line numbers
- URLs are stored in a `set<string>` for uniqueness.

---

## Files

### `text.txt`
The input text file. Should contain at least:
- 1000 words
- A few URLs (e.g., `https://www.vu.lt`, `vu.lt`, `www.vu.lt`, etc.)

### `words.txt`
Contains all words that appear **more than once** in the text, along with how many times they appear.

### `xref.txt`
Cross-reference table showing how often each word occurred and **which lines** they were found on.

### `urls.txt`
Lists all unique URLs found in the text.