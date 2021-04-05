# nearest-neighboring-words

Financial companies extract useful information from bills by locating common data elements on forms with one or more different formats in a 2-step document digitalizatuin process:<br>
	- optical character recognition(OCR), or detection phase<br>
	- data validation phase<br>
	<br>
The most common example of this is Invoice Processing, which identifies the common data elements in an invoive, such as vendor, date, amount, invoice number, line item data.<br>
<br>
1. OCR<br>
Optical Character Recognition (OCR), or the detection phase, translates information from a scanned document(a photo of a document) into text (word blocks with their properties such as position and size in the documents)
<br><br>
2. Data Validation <br>
In data validation step, the aim is to find needed parts, by: <br>
	- identification of useful information from the text scanned <br>
	- validation of information type usefulness (e.g: bill number, manufacturer name, bill issue date, total amount0 by its relative location to other elements <br>
	<br>
Yor are given: <br>
	- a list of words in a text <br>
	- a word index from the initial list of words (starting from 0) <br> <br>

The goal of the problem is to find the nearest top, left, bottom and right neighboring words <br> <br>

Nearest neighboring words:<br>
	- same X coordonate and closet to Y axis, without any intersection <br>
	- or same Y coordonate and closet to X axis, without any intersection. <br> <br>
	
Input: <br>
> Line 1 (number of words) <br>
> Line 2 to (n + 1), words in the text in the form c x y w h(
 c = text, x = top-left corner x position, y = top-left corner y position, w = width, h = height) <br>
> Line (n + 1) index (index of given word for which neighbors are needed) <br> <br>

Example: <br>
Input <br>
9 <br>
text1 6 18 5 2 <br>
text2 0 15 5 2 <br>
text3 6 15 5 2 <br>
text4 0 12 5 2 <br>
text5 6 12 4 2 <br>
text6 12 12 5 2 <br>
text7 6 9 5 2 <br>
text8 0 6 4 2 <br>
text9 6 3 5 2 <br>
<br>
Output<br>
top: text3 <br>
left: text4<br>
bottom: text7<br>
right: text6 <br>
