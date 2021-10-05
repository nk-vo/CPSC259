File:         tide_analyzer.c
Purpose:      Consumes a semi-formatted tide measurement file and
determines if the corresponding tide is once- or
twice-daily using a fast discrete Fourier transformation.
The tide measurement file is a txt file whose name
corresponds to the name defined in the preprocessor
directive.  It is a series of NUMBER_OF_READINGS tidal
readings (in mm) taken hourly.
Author:			  Li Qingyang and Nick Vo
Student #s:		  11056892 and 19308576
CS Accounts:	  	  oxygen16@students.cs.ubc.ca and qli22@student.cs.ubc.ca
Date:		          September 27, 2020