#!/usr/bin/python3
"""
 a recursive function that queries the Reddit API,
 parses the title of all hot articles, and prints
 a sorted count of given keywords
 import requests
"""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Count number of words
    """

    if counts is None:
        counts = {}

    if after is None:
        url = url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)

    else:
        url = "https://www.reddit.com/r/{}/hot.json?after={}".format(subreddit, after)

    headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)\
               AppleWebKit/537.36 (KHTML, like Gecko)\
               Chrome/58.0.3029.110 Safari/537.3"}
    response = requests.get(url, headers=headers)

    if response.status_code == 200:
        data = response.json()
        posts = data["data"]["children"]

        for post in posts:
            title = post["data"]["title"].lower()
            for word in word_list:
                if word.lower() in title:
                    counts[word.lower()] = counts.get(word.lower(), 0)\
                        + title.count(word.lower())

        after = data["data"]["after"]

        if after:
            return count_words(subreddit, word_list, after, counts)
        else:
            sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
            for word, count in sorted_counts:
                print(f"{word}: {count}")
