#!/usr/bin/env python3

#####################################
# Student Name: Tianfu Yuan
# Student ID: 300228072
# NWEN 241 Assignment 2 - world map
#####################################

import psycopg2

#######################################################
# Connect to the database
#
# Variables that may need changing
#
# details for Postgres
myHost = "db.ecs.vuw.ac.nz"
myUser = "worldview"
myPass = "LetMeRoam"    # readonly acccess!
myDB   = "world"
#
########################################################
#
# Make a connection to the database
#
db = psycopg2.connect(host=myHost, user=myUser, password=myPass, database=myDB)
#
# prepare a cursor object using cursor() method
#
cursor = db.cursor()
#
# show details of the tables in the database
#
# build the query
#
sql="SELECT table_name FROM information_schema.tables WHERE table_schema='public'"
#
# ask the question
#
cursor.execute(sql)
#
# get a list of tables
# use fetchall() to get all the rows returned
#
for row in cursor.fetchall():
    table = row[0]
    #
    # display table properties
    #
    print(("Printing details for table '{0}':".format(table)))
    
    sql = """SELECT column_name,data_type,character_maximum_length 
             FROM INFORMATION_SCHEMA.COLUMNS
             WHERE table_name = '{0}'""".format(table)
    cursor.execute(sql)
    
    for row in cursor.fetchall():
        print(row)
    print()
    #
    # print first two rows of table
    #
    sql = """SELECT * FROM {0} LIMIT 2""".format(table)
    print (sql)
    cursor.execute(sql)
    #
    # Use fetchone() to get a row of data
    #
    print(cursor.fetchone())
    print(cursor.fetchone())
    print()

#
# extract data from two tables
#

#sql = """SELECT co.continent, co.name, ci.name, ci.population FROM country co, city ci
#        WHERE co.code = ci.countrycode"""
#cursor.execute(sql)

#for (continent, country, city, population) in cursor.fetchall():
#    print(continent, country, city, population)


#######################################################################################
#                                                                    
#1. The percentage of the world's population who live in cities      
#                                                                    
#######################################################################################    

    sql = """SELECT co.name, co.population FROM country co"""
    cursor.execute(sql)
    
    totalWorldPop = 0
    for (country, population) in cursor.fetchall():
        totalWorldPop = totalWorldPop + population
    
    sql = """SELECT ci.population FROM city ci"""
    cursor.execute(sql)

    totalCityPop = 0
    for (population) in cursor.fetchall():
         totalCityPop = totalCityPop + population[0]
    
    cityPercentage = totalCityPop/totalWorldPop*100
    
    print ('Total population in the world : ', totalWorldPop)
    print ('Total population in the cities : ', totalCityPop)
    print ('The percentage of the worlds population who live in cities: ', cityPercentage, '%')
    print ()

#######################################################################################
#                                                                    
#2. (a) The top five and the bottom five countries - life expectancy
#                                                                    
#######################################################################################

#print out the bottom 5 countries name and life expectancy
    sql = """SELECT co.name, co.lifeExpectancy FROM country co"""
    cursor.execute(sql)
    lifeExpectancy_tuples=[]


    print('Bottom 5 countries in life expenctany: ')
    print('(country name / life expectancy)')
    print()
    
    sql = """SELECT co.name, co.lifeExpectancy FROM country co"""
    cursor.execute(sql)

    countNotZeroPopop = 0
    for (country, lifeExpectancy) in cursor.fetchall():
        if(lifeExpectancy != None):
            countNotZeroPopop = countNotZeroPopop + 1
            lifeExpectancy_tuples.append(lifeExpectancy)

    lifeExpectancy_tuples.sort()

    sql = """SELECT co.name, co.lifeExpectancy FROM country co"""
    
    cursor.execute(sql)
    for (country, lifeExpectancy) in cursor.fetchall():
        if(lifeExpectancy == lifeExpectancy_tuples[0]):
            print(country, lifeExpectancy)
        elif(lifeExpectancy == lifeExpectancy_tuples[1]):
            print(country, lifeExpectancy)
        elif(lifeExpectancy == lifeExpectancy_tuples[2]):
            print(country, lifeExpectancy)
        elif(lifeExpectancy == lifeExpectancy_tuples[3]):
            print(country, lifeExpectancy)
        elif(lifeExpectancy == lifeExpectancy_tuples[4]):
            print(country, lifeExpectancy)
    print()

#print out top 5 countries name and life expectancy
    print('Top 5 countries in life expectancy: ')
    print('(country name / life expectancy)')
    print()
    
    sql = """SELECT co.name, co.lifeExpectancy FROM country co"""
    cursor.execute(sql)
    
    for (country, lifeExpectancy) in cursor.fetchall():
        if(lifeExpectancy == lifeExpectancy_tuples[countNotZeroPopop-1]):
            print(country, lifeExpectancy)
        elif(lifeExpectancy == lifeExpectancy_tuples[countNotZeroPopop-2]):
            print(country, lifeExpectancy)
        elif(lifeExpectancy == lifeExpectancy_tuples[countNotZeroPopop-3]):
            print(country, lifeExpectancy)
        elif(lifeExpectancy == lifeExpectancy_tuples[countNotZeroPopop-4]):
            print(country, lifeExpectancy)
        elif(lifeExpectancy == lifeExpectancy_tuples[countNotZeroPopop-5]):
            print(country, lifeExpectancy)
    print()

#######################################################################################
#                                                                    
#2. (b) The top five and the bottom five countries - population
#                                                                    
#######################################################################################

#print out bottom 5 countries name and population
    sql = """SELECT co.name, co.population FROM country co"""
    cursor.execute(sql)
    population_tuples=[]

    print('Bottom 5 countries in population: ')
    print('(country name / population)')
    print()
    
    sql = """SELECT co.name, co.population FROM country co"""
    cursor.execute(sql)

    countNotZeroPop = 0
    for (country, population) in cursor.fetchall():
        if(population != 0):
            countNotZeroPop = countNotZeroPop+1
            population_tuples.append(population)

    population_tuples.sort()

    sql = """SELECT co.name, co.population FROM country co"""
    cursor.execute(sql)
    
    for (country, population) in cursor.fetchall():
        if(population == population_tuples[0]):
            print(country, population)
        elif(population == population_tuples[1]):
            print(country, population)
        elif(population == population_tuples[2]):
            print(country, population)
        elif(population == population_tuples[3]):
            print(country, population)
        elif(population == population_tuples[4]):
            print(country, population)

    print()

#print out top 5 countries name and population
    print('Top 5 countries in population: ')
    print('(country name / population)')
    print()
    
    sql = """SELECT co.name, co.population FROM country co"""
    cursor.execute(sql)
    
    for (country, population) in cursor.fetchall():
        if(population == population_tuples[countNotZeroPop-1]):
            print(country, population)
        elif(population == population_tuples[countNotZeroPop-2]):
            print(country, population)
        elif(population == population_tuples[countNotZeroPop-3]):
            print(country, population)
        elif(population == population_tuples[countNotZeroPop-4]):
            print(country, population)
        elif(population == population_tuples[countNotZeroPop-5]):
            print(country, population)
    print()

#######################################################################################
#                                                                    
#3. The surface area of each of the coutinents
#                                                                    
#######################################################################################

    print('The surface area of each of the continents: ')
    
    sql = """SELECT co.continent, co.name, co.surfacearea FROM country co"""
    cursor.execute(sql)
    
    asia_tuples=[]
    africa_tuples=[]
    northAmerica_tuples=[]
    southAmerica_tuples=[]
    antarctica_tuples=[]
    europe_tuples=[]
    australia_tuples=[]
    oceania_tuples=[]
    
    Asia = 'Asia'
    Africa = 'Africa'
    North = 'North America'
    South = 'South America'
    Europe = 'Europe'
    Oceania = 'Oceania'
   
    for(continent, country, surfacearea) in cursor.fetchall():
        if(continent == Asia):
           asia_tuples.append(surfacearea)
        elif(continent == Africa):
           africa_tuples.append(surfacearea)
        elif(continent == Europe):
           europe_tuples.append(surfacearea)
        elif(continent == Oceania):
           oceania_tuples.append(surfacearea)
        elif(continent == North):
           northAmerica_tuples.append(surfacearea)
        elif(continent == South):
           southAmerica_tuples.append(surfacearea)        
    print()

    totalAsiaSurface = 0
    for surface in asia_tuples:
        totalAsiaSurface = totalAsiaSurface + surface
    print('Asia: ', totalAsiaSurface)

    totalAfricaSurface = 0
    for surface in africa_tuples:
        totalAfricaSurface = totalAfricaSurface + surface
    print('Africa: ', totalAfricaSurface)

    totalEuropeSurface = 0
    for surface in europe_tuples:
        totalEuropeSurface = totalEuropeSurface + surface
    print('Europe: ', totalEuropeSurface)

    totalOceaniaSurface = 0
    for surface in oceania_tuples:
        totalOceaniaSurface = totalOceaniaSurface + surface
    print('Oceania: ', totalOceaniaSurface)
    
    totalNorthAmericaSurface = 0
    for surface in northAmerica_tuples:
        totalNorthAmericaSurface = totalNorthAmericaSurface + surface
    print('North America: ', totalNorthAmericaSurface)

    totalSouthAmericaSurface = 0
    for surface in southAmerica_tuples:
        totalSouthAmericaSurface = totalSouthAmericaSurface + surface
    print('South America: ', totalSouthAmericaSurface)
   
    print()

#######################################################################################
#                                                                    
#4. The largest and the smallest capital city in population
#                                                                    
#######################################################################################

    sql = """SELECT co.name, co.capital, ci.population FROM country co, city ci"""
    cursor.execute(sql)
    population_tuples=[]
    count = 0
    
    for(country, capital, population) in cursor.fetchall():
           count = count + 1
           population_tuples.append(population)

    population_tuples.sort();

    sql = """SELECT co.name, co.capital, ci.population FROM country co, city ci"""
    cursor.execute(sql)
    for(country, capital, population) in cursor.fetchall():
        if(population == population_tuples[0]):
            print('The smallest capital city in population: ',population)
        elif(population == population_tuples[count-1]):
            print('The largest capital city in population: ', population)
    print()


db.close()