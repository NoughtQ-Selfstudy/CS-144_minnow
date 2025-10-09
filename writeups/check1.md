Checkpoint 1 Writeup
====================

My name: NoughtQ

My SUNet ID: 1145141919810

I collaborated with: Gemini 2.5 pro and GPT-5 (doge)

I would like to thank/reward these classmates for their help: None

This lab took me about 8 hours to do. I did not attend the lab session.

I was surprised by or edified to learn that: Although the task appears minimal (the description provided by the document is brief), it turns out to be quite troublesome to implement, requiring a significant amount of effort and time (perhaps related to my limited coding skills QAQ).

Report from the hands-on component of the lab checkpoint: I cannot accomplish it because I'm not a Stanford student.

Describe Reassembler structure and design. [Describe data structures and
approach taken. Describe alternative designs considered or tested.
Describe benefits and weaknesses of your design compared with
alternatives -- perhaps in terms of simplicity/complexity, risk of
bugs, asymptotic performance, empirical performance, required
implementation time and difficulty, and other factors. Include any
measurements if applicable.]

- Data structure: a mapping from first_index (uint64_t) to substring (std::string) as the internal storage of Reassembler.
    - Benefits: relatively easy to implement the logic for substring merging, and mapping is a straightforward structure that is simple to understand and implement. Plus, the time complexity of insertion of deletion is O(log n) (because of red-black tree), which is relatively fast.
    - Weakness: Cannot access randomly, only sequentially through an iterator.
- I once attempted to use a priority queue (min-heap) because accessing the first element is fast (O(1) complexity), but it was not suitable for merging substrings, as accessing elements one by one in a priority queue is inefficient.

Implementation Challenges: 

Apart from the initial setback of choosing the wrong data structure (initially using a priority queue), I later encountered significant obstacles when implementing the merge operation. My original attempt was to create a function that merged two strings, but this failed to pass the reassembler_win test due to its extremely low efficiency. 

Inspired by Gemini 2.5 Pro, I revised the logic so that each newly read string would attempt to merge with all existing substrings in the buffer, forming a larger string before placing it back into the buffer. This change reduced the time complexity from O(N^2) down to O(N).

Remaining Bugs: not found yet.

- Optional: I had unexpected difficulty with: [describe]

- Optional: I think you could make this lab better by: [describe]

- Optional: I'm not sure about: [describe]
