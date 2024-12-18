#include <stdio.h>
#include <stdlib.h>

void func1(int (*ptr)[4]); // Function using pointer to array of 4 integers

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Main function for demonstrating pointer to array usage.
*
* RETURNS: Nothing
**************************************************************************/
int main() {
    int mat[3][4], i, j;
    int k = 0;

    // Initialize the 2D array
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            mat[i][j] = k++;
        }
    }

    // Print initialized data (address and value)
    printf("Initialized data:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("Address: %p, Value: %d\n", (void*)&mat[i][j], mat[i][j]);
        }
    }

    // Call function that uses pointer to array of 4 integers
    func1(mat);

    return 0;
}

/**************************************************************************
* Function using pointer to array of 4 integers
**************************************************************************/
void func1(int (*ptr)[4]) {
    printf("\nFunction func1 - Accessing 2D array elements:\n");
    
    // Access elements using the pointer to array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Address: %p, Value: %d\n", (void*)&ptr[i][j], ptr[i][j]);
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

void func1(int (*ptr)[4]); // Function using pointer to array of 4 integers

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Main function for demonstrating pointer to array usage.
*
* RETURNS: Nothing
**************************************************************************/
int main() {
    int mat[3][4], i, j;
	    int k = 0;

		    // Initialize the 2D array
			    for (i = 0; i < 3; i++) {
				        for (j = 0; j < 4; j++) {
						            mat[i][j] = k++;
									        }
											    }

												    // Print initialized data (address and value)
													    printf("Initialized data:\n");
														    for (i = 0; i < 3; i++) {
															        for (j = 0; j < 4; j++) {
																	            printf("Address: %p, Value: %d\n", (void*)&mat[i][j], mat[i][j]);
																				        }
																						    }

																							    // Call function that uses pointer to array of 4 integers
																								    func1(mat);

																									    return 0;
																										}

																										/**************************************************************************
																										* Function using pointer to array of 4 integers
																										**************************************************************************/
																										void func1(int (*ptr)[4]) {
																										    printf("\nFunction func1 - Accessing 2D array elements:\n");
																											    
																												    // Access elements using the pointer to array
																													    for (int i = 0; i < 3; i++) {
																														        for (int j = 0; j < 4; j++) {
																																            printf("Address: %p, Value: %d\n", (void*)&ptr[i][j], ptr[i][j]);
																																			        }
																																					    }
																																						}
																																						#include <stdio.h>
																																						#include <stdlib.h>

																																						void func1(int (*ptr)[4]); // Function using pointer to array of 4 integers

																																						/**************************************************************************
																																						*
																																						* FUNCTION NAME: main
																																						*
																																						* DESCRIPTION: Main function for demonstrating pointer to array usage.
																																						*
																																						* RETURNS: Nothing
																																						**************************************************************************/
																																						int main() {
																																						    int mat[3][4], i, j;
																																							    int k = 0;

																																								    // Initialize the 2D array
																																									    for (i = 0; i < 3; i++) {
																																										        for (j = 0; j < 4; j++) {
																																												            mat[i][j] = k++;
																																															        }
																																																	    }

																																																		    // Print initialized data (address and value)
																																																			    printf("Initialized data:\n");
																																																				    for (i = 0; i < 3; i++) {
																																																					        for (j = 0; j < 4; j++) {
																																																							            printf("Address: %p, Value: %d\n", (void*)&mat[i][j], mat[i][j]);
																																																										        }
																																																												    }

																																																													    // Call function that uses pointer to array of 4 integers
																																																														    func1(mat);

																																																															    return 0;
																																																																}

																																																																/**************************************************************************
																																																																* Function using pointer to array of 4 integers
																																																																**************************************************************************/
																																																																void func1(int (*ptr)[4]) {
																																																																    printf("\nFunction func1 - Accessing 2D array elements:\n");
																																																																	    
																																																																		    // Access elements using the pointer to array
																																																																			    for (int i = 0; i < 3; i++) {
																																																																				        for (int j = 0; j < 4; j++) {
																																																																						            printf("Address: %p, Value: %d\n", (void*)&ptr[i][j], ptr[i][j]);
																																																																									        }
																																																																											    }
																																																																												}
																																																																												#include <stdio.h>
																																																																												#include <stdlib.h>

																																																																												void func1(int (*ptr)[4]); // Function using pointer to array of 4 integers

																																																																												/**************************************************************************
																																																																												*
																																																																												* FUNCTION NAME: main
																																																																												*
																																																																												* DESCRIPTION: Main function for demonstrating pointer to array usage.
																																																																												*
																																																																												* RETURNS: Nothing
																																																																												**************************************************************************/
																																																																												int main() {
																																																																												    int mat[3][4], i, j;
																																																																													    int k = 0;

																																																																														    // Initialize the 2D array
																																																																															    for (i = 0; i < 3; i++) {
																																																																																        for (j = 0; j < 4; j++) {
																																																																																		            mat[i][j] = k++;
																																																																																					        }
																																																																																							    }

																																																																																								    // Print initialized data (address and value)
																																																																																									    printf("Initialized data:\n");
																																																																																										    for (i = 0; i < 3; i++) {
																																																																																											        for (j = 0; j < 4; j++) {
																																																																																													            printf("Address: %p, Value: %d\n", (void*)&mat[i][j], mat[i][j]);
																																																																																																        }
																																																																																																		    }

																																																																																																			    // Call function that uses pointer to array of 4 integers
																																																																																																				    func1(mat);

																																																																																																					    return 0;
																																																																																																						}

																																																																																																						/**************************************************************************
																																																																																																						* Function using pointer to array of 4 integers
																																																																																																						**************************************************************************/
																																																																																																						void func1(int (*ptr)[4]) {
																																																																																																						    printf("\nFunction func1 - Accessing 2D array elements:\n");
																																																																																																							    
																																																																																																								    // Access elements using the pointer to array
																																																																																																									    for (int i = 0; i < 3; i++) {
																																																																																																										        for (int j = 0; j < 4; j++) {
																																																																																																												            printf("Address: %p, Value: %d\n", (void*)&ptr[i][j], ptr[i][j]);
																																																																																																															        }
																																																																																																																	    }
																																																																																																																		}
																																																																																																																		#include <stdio.h>
																																																																																																																		#include <stdlib.h>

																																																																																																																		void func1(int (*ptr)[4]); // Function using pointer to array of 4 integers

																																																																																																																		/**************************************************************************
																																																																																																																		*
																																																																																																																		* FUNCTION NAME: main
																																																																																																																		*
																																																																																																																		* DESCRIPTION: Main function for demonstrating pointer to array usage.
																																																																																																																		*
																																																																																																																		* RETURNS: Nothing
																																																																																																																		**************************************************************************/
																																																																																																																		int main() {
																																																																																																																		    int mat[3][4], i, j;
																																																																																																																			    int k = 0;

																																																																																																																				    // Initialize the 2D array
																																																																																																																					    for (i = 0; i < 3; i++) {
																																																																																																																						        for (j = 0; j < 4; j++) {
																																																																																																																								            mat[i][j] = k++;
																																																																																																																											        }
																																																																																																																													    }

																																																																																																																														    // Print initialized data (address and value)
																																																																																																																															    printf("Initialized data:\n");
																																																																																																																																    for (i = 0; i < 3; i++) {
																																																																																																																																	        for (j = 0; j < 4; j++) {
																																																																																																																																			            printf("Address: %p, Value: %d\n", (void*)&mat[i][j], mat[i][j]);
																																																																																																																																						        }
																																																																																																																																								    }

																																																																																																																																									    // Call function that uses pointer to array of 4 integers
																																																																																																																																										    func1(mat);

																																																																																																																																											    return 0;
																																																																																																																																												}

																																																																																																																																												/**************************************************************************
																																																																																																																																												* Function using pointer to array of 4 integers
																																																																																																																																												**************************************************************************/
																																																																																																																																												void func1(int (*ptr)[4]) {
																																																																																																																																												    printf("\nFunction func1 - Accessing 2D array elements:\n");
																																																																																																																																													    
																																																																																																																																														    // Access elements using the pointer to array
																																																																																																																																															    for (int i = 0; i < 3; i++) {
																																																																																																																																																        for (int j = 0; j < 4; j++) {
																																																																																																																																																		            printf("Address: %p, Value: %d\n", (void*)&ptr[i][j], ptr[i][j]);
																																																																																																																																																					        }
																																																																																																																																																							    }
																																																																																																																																																								}
																																																																																																																																																								#include <stdio.h>
																																																																																																																																																								#include <stdlib.h>

																																																																																																																																																								void func1(int (*ptr)[4]); // Function using pointer to array of 4 integers

																																																																																																																																																								/**************************************************************************
																																																																																																																																																								*
																																																																																																																																																								* FUNCTION NAME: main
																																																																																																																																																								*
																																																																																																																																																								* DESCRIPTION: Main function for demonstrating pointer to array usage.
																																																																																																																																																								*
																																																																																																																																																								* RETURNS: Nothing
																																																																																																																																																								**************************************************************************/
																																																																																																																																																								int main() {
																																																																																																																																																								    int mat[3][4], i, j;
																																																																																																																																																									    int k = 0;

																																																																																																																																																										    // Initialize the 2D array
																																																																																																																																																											    for (i = 0; i < 3; i++) {
																																																																																																																																																												        for (j = 0; j < 4; j++) {
																																																																																																																																																														            mat[i][j] = k++;
																																																																																																																																																																	        }
																																																																																																																																																																			    }

																																																																																																																																																																				    // Print initialized data (address and value)
																																																																																																																																																																					    printf("Initialized data:\n");
																																																																																																																																																																						    for (i = 0; i < 3; i++) {
																																																																																																																																																																							        for (j = 0; j < 4; j++) {
																																																																																																																																																																									            printf("Address: %p, Value: %d\n", (void*)&mat[i][j], mat[i][j]);
																																																																																																																																																																												        }
																																																																																																																																																																														    }

																																																																																																																																																																															    // Call function that uses pointer to array of 4 integers
																																																																																																																																																																																    func1(mat);

																																																																																																																																																																																	    return 0;
																																																																																																																																																																																		}

																																																																																																																																																																																		/**************************************************************************
																																																																																																																																																																																		* Function using pointer to array of 4 integers
																																																																																																																																																																																		**************************************************************************/
																																																																																																																																																																																		void func1(int (*ptr)[4]) {
																																																																																																																																																																																		    printf("\nFunction func1 - Accessing 2D array elements:\n");
																																																																																																																																																																																			    
																																																																																																																																																																																				    // Access elements using the pointer to array
																																																																																																																																																																																					    for (int i = 0; i < 3; i++) {
																																																																																																																																																																																						        for (int j = 0; j < 4; j++) {
																																																																																																																																																																																								            printf("Address: %p, Value: %d\n", (void*)&ptr[i][j], ptr[i][j]);
																																																																																																																																																																																											        }
																																																																																																																																																																																													    }
																																																																																																																																																																																														}
																																																																																																																																																																																														#include <stdio.h>
																																																																																																																																																																																														#include <stdlib.h>

																																																																																																																																																																																														void func1(int (*ptr)[4]); // Function using pointer to array of 4 integers

																																																																																																																																																																																														/**************************************************************************
																																																																																																																																																																																														*
																																																																																																																																																																																														* FUNCTION NAME: main
																																																																																																																																																																																														*
																																																																																																																																																																																														* DESCRIPTION: Main function for demonstrating pointer to array usage.
																																																																																																																																																																																														*
																																																																																																																																																																																														* RETURNS: Nothing
																																																																																																																																																																																														**************************************************************************/
																																																																																																																																																																																														int main() {
																																																																																																																																																																																														    int mat[3][4], i, j;
																																																																																																																																																																																															    int k = 0;

																																																																																																																																																																																																    // Initialize the 2D array
																																																																																																																																																																																																	    for (i = 0; i < 3; i++) {
																																																																																																																																																																																																		        for (j = 0; j < 4; j++) {
																																																																																																																																																																																																				            mat[i][j] = k++;
																																																																																																																																																																																																							        }
																																																																																																																																																																																																									    }

																																																																																																																																																																																																										    // Print initialized data (address and value)
																																																																																																																																																																																																											    printf("Initialized data:\n");
																																																																																																																																																																																																												    for (i = 0; i < 3; i++) {
																																																																																																																																																																																																													        for (j = 0; j < 4; j++) {
																																																																																																																																																																																																															            printf("Address: %p, Value: %d\n", (void*)&mat[i][j], mat[i][j]);
																																																																																																																																																																																																																		        }
																																																																																																																																																																																																																				    }

																																																																																																																																																																																																																					    // Call function that uses pointer to array of 4 integers
																																																																																																																																																																																																																						    func1(mat);

																																																																																																																																																																																																																							    return 0;
																																																																																																																																																																																																																								}

																																																																																																																																																																																																																								/**************************************************************************
																																																																																																																																																																																																																								* Function using pointer to array of 4 integers
																																																																																																																																																																																																																								**************************************************************************/
																																																																																																																																																																																																																								void func1(int (*ptr)[4]) {
																																																																																																																																																																																																																								    printf("\nFunction func1 - Accessing 2D array elements:\n");
																																																																																																																																																																																																																									    
																																																																																																																																																																																																																										    // Access elements using the pointer to array
																																																																																																																																																																																																																											    for (int i = 0; i < 3; i++) {
																																																																																																																																																																																																																												        for (int j = 0; j < 4; j++) {
																																																																																																																																																																																																																														            printf("Address: %p, Value: %d\n", (void*)&ptr[i][j], ptr[i][j]);
																																																																																																																																																																																																																																	        }
																																																																																																																																																																																																																																			    }
																																																																																																																																																																																																																																				}
																																																																																																																																																																																																																																				#include <stdio.h>
																																																																																																																																																																																																																																				#include <stdlib.h>

																																																																																																																																																																																																																																				void func1(int (*ptr)[4]); // Function using pointer to array of 4 integers

																																																																																																																																																																																																																																				/**************************************************************************
																																																																																																																																																																																																																																				*
																																																																																																																																																																																																																																				* FUNCTION NAME: main
																																																																																																																																																																																																																																				*
																																																																																																																																																																																																																																				* DESCRIPTION: Main function for demonstrating pointer to array usage.
																																																																																																																																																																																																																																				*
																																																																																																																																																																																																																																				* RETURNS: Nothing
																																																																																																																																																																																																																																				**************************************************************************/
																																																																																																																																																																																																																																				int main() {
																																																																																																																																																																																																																																				    int mat[3][4], i, j;
																																																																																																																																																																																																																																					    int k = 0;

																																																																																																																																																																																																																																						    // Initialize the 2D array
																																																																																																																																																																																																																																							    for (i = 0; i < 3; i++) {
																																																																																																																																																																																																																																								        for (j = 0; j < 4; j++) {
																																																																																																																																																																																																																																										            mat[i][j] = k++;
																																																																																																																																																																																																																																													        }
																																																																																																																																																																																																																																															    }

																																																																																																																																																																																																																																																    // Print initialized data (address and value)
																																																																																																																																																																																																																																																	    printf("Initialized data:\n");
																																																																																																																																																																																																																																																		    for (i = 0; i < 3; i++) {
																																																																																																																																																																																																																																																			        for (j = 0; j < 4; j++) {
																																																																																																																																																																																																																																																					            printf("Address: %p, Value: %d\n", (void*)&mat[i][j], mat[i][j]);
																																																																																																																																																																																																																																																								        }
																																																																																																																																																																																																																																																										    }

																																																																																																																																																																																																																																																											    // Call function that uses pointer to array of 4 integers
																																																																																																																																																																																																																																																												    func1(mat);

																																																																																																																																																																																																																																																													    return 0;
																																																																																																																																																																																																																																																														}

																																																																																																																																																																																																																																																														/**************************************************************************
																																																																																																																																																																																																																																																														* Function using pointer to array of 4 integers
																																																																																																																																																																																																																																																														**************************************************************************/
																																																																																																																																																																																																																																																														void func1(int (*ptr)[4]) {
																																																																																																																																																																																																																																																														    printf("\nFunction func1 - Accessing 2D array elements:\n");
																																																																																																																																																																																																																																																															    
																																																																																																																																																																																																																																																																    // Access elements using the pointer to array
																																																																																																																																																																																																																																																																	    for (int i = 0; i < 3; i++) {
																																																																																																																																																																																																																																																																		        for (int j = 0; j < 4; j++) {
																																																																																																																																																																																																																																																																				            printf("Address: %p, Value: %d\n", (void*)&ptr[i][j], ptr[i][j]);
																																																																																																																																																																																																																																																																							        }
																																																																																																																																																																																																																																																																									    }
																																																																																																																																																																																																																																																																										}
																																																																																																																																																																																																																																																																										#include <stdio.h>
																																																																																																																																																																																																																																																																										#include <stdlib.h>

																																																																																																																																																																																																																																																																										void func1(int (*ptr)[4]); // Function using pointer to array of 4 integers

																																																																																																																																																																																																																																																																										/**************************************************************************
																																																																																																																																																																																																																																																																										*
																																																																																																																																																																																																																																																																										* FUNCTION NAME: main
																																																																																																																																																																																																																																																																										*
																																																																																																																																																																																																																																																																										* DESCRIPTION: Main function for demonstrating pointer to array usage.
																																																																																																																																																																																																																																																																										*
																																																																																																																																																																																																																																																																										* RETURNS: Nothing
																																																																																																																																																																																																																																																																										**************************************************************************/
																																																																																																																																																																																																																																																																										int main() {
																																																																																																																																																																																																																																																																										    int mat[3][4], i, j;
																																																																																																																																																																																																																																																																											    int k = 0;

																																																																																																																																																																																																																																																																												    // Initialize the 2D array
																																																																																																																																																																																																																																																																													    for (i = 0; i < 3; i++) {
																																																																																																																																																																																																																																																																														        for (j = 0; j < 4; j++) {
																																																																																																																																																																																																																																																																																            mat[i][j] = k++;
																																																																																																																																																																																																																																																																																			        }
																																																																																																																																																																																																																																																																																					    }

																																																																																																																																																																																																																																																																																						    // Print initialized data (address and value)
																																																																																																																																																																																																																																																																																							    printf("Initialized data:\n");
																																																																																																																																																																																																																																																																																								    for (i = 0; i < 3; i++) {
																																																																																																																																																																																																																																																																																									        for (j = 0; j < 4; j++) {
																																																																																																																																																																																																																																																																																											            printf("Address: %p, Value: %d\n", (void*)&mat[i][j], mat[i][j]);
																																																																																																																																																																																																																																																																																														        }
																																																																																																																																																																																																																																																																																																    }

																																																																																																																																																																																																																																																																																																	    // Call function that uses pointer to array of 4 integers
																																																																																																																																																																																																																																																																																																		    func1(mat);

																																																																																																																																																																																																																																																																																																			    return 0;
																																																																																																																																																																																																																																																																																																				}

																																																																																																																																																																																																																																																																																																				/**************************************************************************
																																																																																																																																																																																																																																																																																																				* Function using pointer to array of 4 integers
																																																																																																																																																																																																																																																																																																				**************************************************************************/
																																																																																																																																																																																																																																																																																																				void func1(int (*ptr)[4]) {
																																																																																																																																																																																																																																																																																																				    printf("\nFunction func1 - Accessing 2D array elements:\n");
																																																																																																																																																																																																																																																																																																					    
																																																																																																																																																																																																																																																																																																						    // Access elements using the pointer to array
																																																																																																																																																																																																																																																																																																							    for (int i = 0; i < 3; i++) {
																																																																																																																																																																																																																																																																																																								        for (int j = 0; j < 4; j++) {
																																																																																																																																																																																																																																																																																																										            printf("Address: %p, Value: %d\n", (void*)&ptr[i][j], ptr[i][j]);
																																																																																																																																																																																																																																																																																																													        }
																																																																																																																																																																																																																																																																																																															    }
																																																																																																																																																																																																																																																																																																																}

