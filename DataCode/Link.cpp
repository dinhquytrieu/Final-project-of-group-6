#include "Header.h"
#include "course.h"
#include <conio.h>
int maiṇ̣̣()
{
	year* pYear;
	//loadData(pYear);
	char ch;
	int mainmenu = 0;
	do
	{
		// main menu taskbar
		//move func
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 75)
			{
				//move left
			}
			else if (ch == 77)
			{
				//move right
			}
			
		}
		if (ch == 13)
		{
			if (mainmenu == 0)
			{
				// year
				int yearmenu = 0;
				do {
					//year menu taskbar
					//move func
					ch = _getch();
					if (ch == -32)
					{
						ch = _getch();
						if (ch == 75)
						{
							//move left
						}
						else if (ch == 77)
						{
							//move right
						}
					}
					if (ch == 13)
					{
						if (yearmenu == 0)
						{
							// new a year
						}
						if (yearmenu == 1)
						{
							// Access a year
							// choose a year
							//1. 2. 3. 4.
							//cin>> ?;
							int AccessYearMenu = 0;
							do {
								//Access year menu taskbar(specific year!)
								//move func
								ch = _getch();
								if (ch == -32)
								{
									ch = _getch();
									if (ch == 75)
									{
										//move left
									}
									else if (ch == 77)
									{
										//move right
									}
								}
								if (ch == 13)
								{
									if (AccessYearMenu == 0)
									{
										// class menu
										int ClassMenu = 0;
										do {
											//class menu taskbar
											//move func
										
											ch = _getch();
											if (ch == -32)
											{
												ch = _getch();
												if (ch == 75)
												{
													//move left
												}
												else if (ch == 77)
												{
													//move right
												}
											}
											if (ch == 13)
											{
												if (ClassMenu == 0)
												{
													//new a class
												}
												if (ClassMenu == 1)
												{
													//access a class
													// choose a class
													//specific class
													//cin>> ? (21clc10,21clc01,...)
													int AccessClassMenu = 0;
													do {
														//access a specific class
														
														ch = _getch();
														if (ch == -32)
														{
															ch = _getch();
															if (ch == 75)
															{
																//move left
															}
															else if (ch == 77)
															{
																//move right
															}
														}
														if (ch == 13)
														{
															if (AccessClassMenu == 0)
															{
																//add student
																int AddStudent = 0;
																do
																{
																	ch = _getch();
																	if (ch == -32)
																	{
																		ch = _getch();
																		if (ch == 75)
																		{
																			//move left
																		}
																		else if (ch == 77)
																		{
																			//move right
																		}
																	}
																	if (ch == 13)
																	{
																		if (AddStudent == 0)
																		{
																			//add manual
																		}
																		if (AddStudent == 1)
																		{
																			//csv.file
																		}
																		if (AddStudent == 2)
																		{
																			//back
																			break;
																		}
																	}
																} while (ch != 27);
															}
															if (AccessClassMenu == 1)
															{
																//score board
															}
															if (AccessClassMenu == 2)
															{
																//back
																break;
															}
														}
													} while (ch != 27);
												}
												if (ClassMenu == 2)
												{
													//back
													break;
												}
											}
										} while (ch != 27);
									}
									else if (AccessYearMenu == 1)
									{
										//semester menu
										int SemesterMenu = 0;
										do
										{
											ch = _getch();
											if (ch == -32)
											{
												ch = _getch();
												if (ch == 75)
												{
													//move left
												}
												else if (ch == 77)
												{
													//move right
												}
											}
											if (ch == 13)
											{
												if (SemesterMenu == 0)
												{
													//new a semester
												}
												if (SemesterMenu == 1)
												{
													//access a specific semester
													// choose a specific semester (1,2 or 3)
													//cin>> ?
													int AccessSemesterMenu = 0;
													do {
														//access a specific class

														ch = _getch();
														if (ch == -32)
														{
															ch = _getch();
															if (ch == 75)
															{
																//move left
															}
															else if (ch == 77)
															{
																//move right
															}
														}
														if (ch == 13)
														{
															if (AccessSemesterMenu == 0)
															{
																//registation 
															}
															if (AccessSemesterMenu == 1)
															{
																//course
																int courseMenu = 0;
																do {
																	//access a specific class

																	ch = _getch();
																	if (ch == -32)
																	{
																		ch = _getch();
																		if (ch == 75)
																		{
																			//move left
																		}
																		else if (ch == 77)
																		{
																			//move right
																		}
																	}
																	if (ch == 13)
																	{
																		if (courseMenu == 0)
																		{
																			//access courses
																			//print list of courses and choose 1
																			//cin>> ?;
																			int AccesscourseMenu = 0;
																			do {
																				//access a specific courses

																				ch = _getch();
																				if (ch == -32)
																				{
																					ch = _getch();
																					if (ch == 75)
																					{
																						//move left
																					}
																					else if (ch == 77)
																					{
																						//move right
																					}
																				}
																				if (ch == 13)
																				{
																					if (AccesscourseMenu == 0)
																					{
																						//update courses
																					}
																					if (AccesscourseMenu == 1)
																					{
																						//info
																						int CourseInfo = 0;
																						do {
																							//access a specific courses

																							ch = _getch();
																							if (ch == -32)
																							{
																								ch = _getch();
																								if (ch == 75)
																								{
																									//move left
																								}
																								else if (ch == 77)
																								{
																									//move right
																								}
																							}
																							if (ch == 13)
																							{
																								if (CourseInfo == 0)
																								{
																									//student
																								}
																								if (CourseInfo == 1)
																								{
																									//scoreboard
																								}
																								if (CourseInfo == 2)
																								{
																									//back
																									break;
																								}
																							}
																						} while (ch != 27);
																					}
																					if (AccesscourseMenu == 2)
																					{
																						//delete course
																					}
																					if (AccesscourseMenu == 3)
																					{
																						//back
																						break;
																					}
																				}
																			} while (ch != 27);
																		}
																		if (courseMenu == 1)
																		{
																			//add courses
																		}
																		if (courseMenu == 2)
																		{
																			//view courses
																		}
																		if (courseMenu == 3)
																		{
																			//back
																			break;
																		}
																	}
																} while (ch != 27);
															}
															if (AccessSemesterMenu == 2)
															{
																//back
																break;
															}
														}
													} while (ch != 27);
												}
												if (SemesterMenu == 2)
												{
													//back
													break;
												}
											}
										} while (ch != 27);
									}
									else if (AccessYearMenu == 2)
									{
										//back
										break;
									}
								}
							} while (ch != 27);
						}
						if (yearmenu == 2)
						{
							// back
							break;
						}
					}
				} while (ch != 27);
			}
			if (mainmenu == 1)
			{
				// change pass
			}
			if (mainmenu == 2)
			{
				//log out
				break;
			}
		}

	} while (ch != 27);
}