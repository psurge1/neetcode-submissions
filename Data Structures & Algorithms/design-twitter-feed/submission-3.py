class Twitter:

    def __init__(self):
        self.following = defaultdict(set)
        self.user_tweets = defaultdict(list)
        self.time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.user_tweets[userId].append((self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        self.following[userId].add(userId)
        following = {fid: len(self.user_tweets[fid]) - 1 for fid in self.following[userId]}
        heap = []
        for f in following:
            tweet_idx = following[f]
            if tweet_idx >= 0:
                tweet = self.user_tweets[f][tweet_idx]
                heapq.heappush(heap, (-tweet[0], tweet[1], f))
                following[f] -= 1
        feed = []
        count = 0
        while count < 10 and len(heap) > 0:
            most_recent_tweet = heapq.heappop(heap)
            feed.append(most_recent_tweet[1])
            f = most_recent_tweet[2]
            tweet_idx = following[f]
            if tweet_idx >= 0:
                tweet = self.user_tweets[f][tweet_idx]
                heapq.heappush(heap, (-tweet[0], tweet[1], f))
                following[f] -= 1
            count += 1
        return feed


    def follow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].discard(followeeId)
