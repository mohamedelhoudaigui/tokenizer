Step-by-Step Guide to Implement Byte Pair Encoding (BPE)
1. Preprocessing
Input: Raw text corpus

Steps:

Normalize text (lowercase, remove special characters, etc.)

Split text into words

Add a special end-of-word token (e.g., </w>) to each word

Count word frequencies

Output: List of words with frequencies: {"low": 5, "lower": 2, "newest": 3, ...}

2. Initialize Vocabulary
Input: Preprocessed words

Steps:

Split each word into characters

Create a base vocabulary of unique characters + special tokens

Include end-of-word token (</w>) in base vocab

Output: Initial vocabulary (e.g., { 'l', 'o', 'w', 'e', 'r', 'n', ... '</w>' })

3. Build Initial Token Pairs
Input: Words split into characters with frequencies

Steps:

For each word, create character pairs with positions:

"low</w>" → (l,o), (o,w), (w,</w>)

Count frequency of each pair across all words

Output: Pair frequencies: {(l,o): 5, (o,w): 7, (w,</w>): 5, ...}

4. Merge Most Frequent Pair
Input: Pair frequencies

Steps:

Find highest-frequency pair (e.g., (e,s): 15 occurrences)

Merge this pair into a new token (e.g., es)

Update vocabulary: Add es

Replace all occurrences of e + s with es in all words

Recalculate pair frequencies with updated tokens

Output: Updated word tokens and vocabulary

5. Repeat Merging
Input: Updated tokens and pair frequencies

Steps:

Repeat Step 4 until:

Vocabulary reaches target size (e.g., 10k tokens), OR

No more merges possible

Track merge operations in order (critical for encoding)

Output:

Final vocabulary (e.g., { 'the', 'ing', 'es', 'low', ... })

Merge rules: [(e,s)→es, (es,t)→est, ...]

6. Encode New Text
Input: New word (e.g., "lowest")

Steps:

Split into characters + </w>: [l, o, w, e, s, t, </w>]

Apply merge rules in order:

Merge e+s → es → [l, o, w, es, t, </w>]

Merge es+t → est → [l, o, w, est, </w>]

(No further merges if no rules match)

Final tokens: [low, est, </w>] (if low is in vocabulary)

Output: Encoded tokens

Key Considerations
End-of-Word Token (</w>):

Distinguishes word boundaries (e.g., est vs. est</w>)

Prevents ambiguous merges across words

Handling Unknown Characters:

Reserve an <UNK> token for unseen characters

Replace unknowns during encoding

Merge Priority:

Apply merges in the exact order learned during training

Greedy merging (highest frequency first) is crucial

Vocabulary Size:

Start with base characters (vocab size ~100-256)

Stop when reaching target size (e.g., 10k-50k for NLP)

Efficiency:

Use priority queues for tracking frequent pairs

Precompute frequencies in batches

Example Walkthrough
Corpus: ["low</w>", "low</w>", "newer</w>", "wider</w>"]
Step 1: Most common pair: (e,r) (appears in newer, wider)
Merge: Create er → ["low</w>", "low</w>", "newer</w>", "wid er</w>"]
Step 2: Next pair: (l,o) (in low)
Merge: Create lo → ["lo w</w>", "lo w</w>", "newer</w>", "wid er</w>"]
Final Vocabulary: {l, o, w, e, r, n, d, i, er, lo, ...}

Saving the Model
Save two files:

Vocabulary: List of all tokens

Merge Rules: Ordered list of merges
Format: e s → es
es t → est