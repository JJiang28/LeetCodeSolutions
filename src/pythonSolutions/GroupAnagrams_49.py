class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #to initialize an array of size 26
        groups = defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1
            groups[tuple(count)].append(s)
        return groups.values()
