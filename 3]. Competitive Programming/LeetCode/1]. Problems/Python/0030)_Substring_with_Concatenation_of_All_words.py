class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        result = []
        word_len = len(words[0])
        
        for stripe in range(word_len):
            i = stripe
            to_match = len(words)
            freq = Counter(words)
            
            while i+to_match*word_len <= len(s):
                word = s[i:i+word_len]
                if word in freq:
                    freq[word] -= 1
                    if freq[word] == 0:
                        del freq[word]
                    to_match -= 1
                    i += word_len
                    if to_match == 0:
                        result.append(i - word_len*len(words))
                elif to_match != len(words):
                    nb_matches = len(words) - to_match
                    first_word = s[i - nb_matches*word_len:i - (nb_matches-1)*word_len]
                    freq.setdefault(first_word, 0)
                    freq[first_word] += 1
                    to_match += 1
                else:
                    i += word_len
        return result