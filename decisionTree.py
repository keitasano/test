import numpy as np
import pandas as pd
import math
import sys

class Node:

    def __init__(self, name, informationGain, threshold, datas, parentNode, leftNode, rightNode):
        # column name
        self.name = name
        # informationGain
        self.informationGain = informationGain
        # threshold for divide
        self.threshold = threshold
        # datas of node
        self.datas = datas
        # parentNode
        self.parentNode = parentNode
        # leftNode
        self.leftNode = leftNode
        # rightNode
        self.rightNode = rightNode

    # return True, if all datas of node is same class
    def isLeaf(self):
        dataIndexLength = len(self.datas.index)
        dataColumnLength = len(self.datas.columns)

        for i in range(dataIndexLength - 1):
            for j in range(1, dataIndexLength):
                if self.datas.iloc[i].iloc[dataColumnLength - 1] != self.datas.iloc[j].iloc[dataColumnLength - 1]:
                    return False

        return True

    def toString(self):
        print("column_name = {}\n"
              "information_gain = {}\n"
              "threshold = {}\n"
              .format(self.name, self.informationGain, self.threshold))

        print("right = {}\n".format(self.rightNode.informationGain))
        print("left = {}\n".format(self.leftNode.informationGain))


# trainData is only class
def calc_information_gain(trainData, rootLength):

    # extract class column
    trainData = trainData.iloc[:, len(trainData.columns) - 1]

    # length of index
    parameter = len(trainData.index)

    # count nums of each class
    categoryDict = {}
    for data in trainData:
        if data in categoryDict:
            categoryDict[data] += 1
        else:
            categoryDict[data] = 1

    informationGain = 0
    for value in categoryDict.values():
        probability = value/parameter
        informationGain += -probability * math.log(probability, 2)

    return (parameter / rootLength) * informationGain


# make dicision tree by ID3
def makeDecisionTree(node : Node) -> Node:

    # length of columns
    dataColumnLength = len(node.datas.columns)
    # length of index
    dataIndexLength = len(node.datas.index)

    # finish recursive, if node is leaf
    if node.isLeaf():
        node.name = node.datas.iloc[0].iloc[dataColumnLength - 1]
        print(node.name)
        return

    rightNode = Node("", 0, 0, None, node, None, None)
    leftNode = Node("", 0, 0, None, node, None, None)

    maxInformationGain = 0
    for column in range(dataColumnLength - 1):
        tmpInformationGain = -1

        columnName = node.datas.columns[column]
        sortedTrainData = node.datas.sort_values(by=columnName)

        # for calc threshold (maxsize)
        beforeTmpThreshold = sys.maxsize
        for index in range(1, dataIndexLength):

            if sortedTrainData.iloc[index].iloc[dataColumnLength - 1] != sortedTrainData.iloc[index - 1].iloc[dataColumnLength - 1]:
                # calc information gain
                curTmpThreshold = (sortedTrainData.iloc[index].loc[columnName] + sortedTrainData.iloc[index - 1].loc[columnName]) / 2

                # if calc informationGain by threshold that is reuse
                if curTmpThreshold == beforeTmpThreshold:
                    continue

                # calc InformationGain of RootNode
                rootNodeData = sortedTrainData
                tmpRootInformationGain = calc_information_gain(rootNodeData , dataIndexLength)

                # calc InformationGain of leftNode
                leftNodeData = sortedTrainData[sortedTrainData.loc[:, columnName] < curTmpThreshold]
                tmpLeftNodeInformationGain = calc_information_gain(leftNodeData, dataIndexLength)

                # calc InformationGain of RightNode
                rightNodeData = sortedTrainData[sortedTrainData.loc[:, columnName] >= curTmpThreshold]
                tmpRightNodeInformationGain = calc_information_gain(rightNodeData, dataIndexLength)

                # sum InformationGain based RootNode
                tmpInformationGain = tmpRootInformationGain - (tmpLeftNodeInformationGain + tmpRightNodeInformationGain)
                beforeTmpThreshold = curTmpThreshold

                if maxInformationGain < tmpInformationGain:
                    node.name = columnName
                    node.informationGain = tmpRootInformationGain
                    node.threshold = curTmpThreshold
                    node.datas = rootNodeData

                    leftNode.informationGain = tmpLeftNodeInformationGain
                    leftNode.datas = leftNodeData

                    rightNode.informationGain = tmpRightNodeInformationGain
                    rightNode.datas = rightNodeData

                    maxInformationGain = tmpInformationGain

    node.leftNode = leftNode
    node.rightNode = rightNode

    print(node.toString())

    makeDecisionTree(node.leftNode)
    makeDecisionTree(node.rightNode)


if __name__ == '__main__':

    # trainデータ読み込み(dataframe)
    trainData = pd.read_table("iris2.txt", delimiter = ",", header = 0)

    # define root node
    rootNode = Node("", 0, 0, trainData, None, None, None)

    # make decision tree
    makeDecisionTree(rootNode)
