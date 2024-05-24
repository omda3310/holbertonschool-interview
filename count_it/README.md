
COUNT IT

## Description
This Python script utilizes the Reddit API to query a specified subreddit, parse the titles of its hot articles, and count the occurrences of given keywords. The counts are printed in descending order based on the number of occurrences, with alphabetical sorting for keywords with the same count.

## Requirements
- Python 3.x
- Requests library (`pip install requests`)

## Usage
To use this script, follow these steps:
1. Clone the repository:
  
   git clone https://github.com/omda3310/holbertonschool-interview.git
Navigate to the project directory:

cd your_repository
Run the script using the following command:

python3 count_words.py subreddit keyword1 keyword2 ...
Replace subreddit with the name of the subreddit you want to query, and keyword1, keyword2, etc. with the keywords you want to count. Multiple keywords should be separated by spaces.

Example

python3 count_words.py programming 'react python java javascript scala no_results_for_this_one'
Output:

makefile

java: 27
javascript: 20
python: 17
react: 17
scala: 4

Notes
Invalid subreddits may return a redirect to search results. Ensure that you are NOT following redirects.
If no posts match or the subreddit is invalid, nothing will be printed.
The script recursively calls itself to paginate through the Reddit API responses until all hot articles are retrieved.
License
This project is licensed under the MIT License - see the LICENSE file for details.
