import unittest
from graph import Graph, test_data1, test_data2

# test_data1 = {
#     "nodes": [
#         "CDHDR",
#         "BKPF",
#         "CDPOS",
#         "SWWLOGHIST",
#         "TVZBT",
#         "SWW_WI2OBJ",
#         "TMP_AP_BKPF_BSEG_1",
#         "T042Z",
#         "USR02",
#         "T003T",
#         "LFB1",
#         "TMP_AP_BKPF_BSEG",
#         "BSEG",
#         "PSIIC_HEAD",
#         "_CEL_AP_CASES_VIEW",
#         "TBSLT",
#         "LFA1",
#         "REGUP",
#         "BSEC",
#         "_CEL_AP_CASES_VIEW_1",
#         "T052U",
#         "EKPO",
#     ],
#     "edges": [
#         # CDHDR
#         ("CDHDR", "CDPOS"),
#         ("CDHDR", "USR02"),
#         # BKPF
#         ("BKPF", "TMP_AP_BKPF_BSEG"),
#         ("BKPF", "LFA1"),
#         ("BKPF", "_CEL_AP_CASES_VIEW_1"),
#         ("BKPF", "BSEG"),
#         ("BKPF", "PSIIC_HEAD"),
#         ("BKPF", "REGUP"),
#         ("BKPF", "LFB1"),
#         ("BKPF", "SWW_WI2OBJ"),
#         ("BKPF", "_CEL_AP_CASES_VIEW"),
#         ("BKPF", "USR02"),
#         ("BKPF", "T003T"),
#         ("BKPF", "TMP_AP_BKPF_BSEG_1"),
#         ("BKPF", "CDPOS"),
#         # CDPOS
#         ("CDPOS", "CDHDR"),
#         ("CDPOS", "BKPF"),
#         ("CDPOS", "TMP_AP_BKPF_BSEG"),
#         ("CDPOS", "PSIIC_HEAD"),
#         ("CDPOS", "_CEL_AP_CASES_VIEW"),
#         ("CDPOS", "TMP_AP_BKPF_BSEG_1"),
#         # SWWLOGHIST
#         ("SWWLOGHIST", "SWW_WI2OBJ"),
#         # TMP_AP_BKPF_BSEG_1
#         ("TMP_AP_BKPF_BSEG_1", "BKPF"),
#         ("TMP_AP_BKPF_BSEG_1", "TVZBT"),
#         ("TMP_AP_BKPF_BSEG_1", "SWW_WI2OBJ"),
#         ("TMP_AP_BKPF_BSEG_1", "T042Z"),
#         ("TMP_AP_BKPF_BSEG_1", "USR02"),
#         ("TMP_AP_BKPF_BSEG_1", "TMP_AP_BKPF_BSEG"),
#         ("TMP_AP_BKPF_BSEG_1", "BSEG"),
#         ("TMP_AP_BKPF_BSEG_1", "LFB1"),
#         ("TMP_AP_BKPF_BSEG_1", "LFA1"),
#         ("TMP_AP_BKPF_BSEG_1", "TBSLT"),
#         ("TMP_AP_BKPF_BSEG_1", "PSIIC_HEAD"),
#         ("TMP_AP_BKPF_BSEG_1", "_CEL_AP_CASES_VIEW_1"),
#         ("TMP_AP_BKPF_BSEG_1", "REGUP"),
#         ("TMP_AP_BKPF_BSEG_1", "T052U"),
#         ("TMP_AP_BKPF_BSEG_1", "_CEL_AP_CASES_VIEW"),
#         # TVZBT
#         ("TVZBT", "LFA1"),
#         ("TVZBT", "_CEL_AP_CASES_VIEW_1"),
#         ("TVZBT", "BSEG"),
#         ("TVZBT", "_CEL_AP_CASES_VIEW"),
#         ("TVZBT", "LFB1"),
#         ("TVZBT", "TMP_AP_BKPF_BSEG_1"),
#         # T042Z
#         ("T042Z", "_CEL_AP_CASES_VIEW_1"),
#         ("T042Z", "T052U"),
#         ("T042Z", "_CEL_AP_CASES_VIEW"),
#         ("T042Z", "TMP_AP_BKPF_BSEG_1"),
#         # SWW_WI2OBJ
#         ("SWW_WI2OBJ", "SWWLOGHIST"),
#         ("SWW_WI2OBJ", "BKPF"),
#         ("SWW_WI2OBJ", "_CEL_AP_CASES_VIEW"),
#         ("SWW_WI2OBJ", "TMP_AP_BKPF_BSEG_1"),
#         # USR02
#         ("USR02", "CDHDR"),
#         ("USR02", "BKPF"),
#         ("USR02", "PSIIC_HEAD"),
#         ("USR02", "TMP_AP_BKPF_BSEG"),
#         ("USR02", "_CEL_AP_CASES_VIEW"),
#         # TMP_AP_BKPF_BSEG
#         ("TMP_AP_BKPF_BSEG", "LFA1"),
#         ("TMP_AP_BKPF_BSEG", "_CEL_AP_CASES_VIEW_1"),
#         ("TMP_AP_BKPF_BSEG", "T052U"),
#         ("TMP_AP_BKPF_BSEG", "TBSLT"),
#         ("TMP_AP_BKPF_BSEG", "REGUP"),
#         ("TMP_AP_BKPF_BSEG", "EKPO"),
#         ("TMP_AP_BKPF_BSEG", "PSIIC_HEAD"),
#         ("TMP_AP_BKPF_BSEG", "_CEL_AP_CASES_VIEW"),
#         ("TMP_AP_BKPF_BSEG", "BSEG"),
#         ("TMP_AP_BKPF_BSEG", "LFB1"),
#         ("TMP_AP_BKPF_BSEG", "TMP_AP_BKPF_BSEG_1"),
#         ("TMP_AP_BKPF_BSEG", "USR02"),
#         ("TMP_AP_BKPF_BSEG", "SWW_WI2OBJ"),
#         ("TMP_AP_BKPF_BSEG", "CDPOS"),
#         ("TMP_AP_BKPF_BSEG", "T042Z"),
#         ("TMP_AP_BKPF_BSEG", "BKPF"),
#         ("TMP_AP_BKPF_BSEG", "TVZBT"),
#         # BSEG
#         ("BSEG", "BKPF"),
#         ("BSEG", "TMP_AP_BKPF_BSEG"),
#         ("BSEG", "LFA1"),
#         ("BSEG", "BSEC"),
#         ("BSEG", "TBSLT"),
#         ("BSEG", "_CEL_AP_CASES_VIEW_1"),
#         ("BSEG", "_CEL_AP_CASES_VIEW"),
#         # LFB1
#         ("LFB1", "BKPF"),
#         ("LFB1", "TVZBT"),
#         ("LFB1", "_CEL_AP_CASES_VIEW_1"),
#         ("LFB1", "T052U"),
#         ("LFB1", "_CEL_AP_CASES_VIEW"),
#         # T003T
#         ("T003T", "BKPF"),
#         ("T003T", "_CEL_AP_CASES_VIEW"),
#         # _CEL_AP_CASES_VIEW
#         ("_CEL_AP_CASES_VIEW", "T003T"),
#         ("_CEL_AP_CASES_VIEW", "TMP_AP_BKPF_BSEG_1"),
#         ("_CEL_AP_CASES_VIEW", "CDPOS"),
#         ("_CEL_AP_CASES_VIEW", "USR02"),
#         ("_CEL_AP_CASES_VIEW", "BKPF"),
#         ("_CEL_AP_CASES_VIEW", "SWW_WI2OBJ"),
#         ("_CEL_AP_CASES_VIEW", "LFB1"),
#         ("_CEL_AP_CASES_VIEW", "T042Z"),
#         ("_CEL_AP_CASES_VIEW", "TVZBT"),
#         ("_CEL_AP_CASES_VIEW", "BSEG"),
#         ("_CEL_AP_CASES_VIEW", "TMP_AP_BKPF_BSEG"),
#         ("_CEL_AP_CASES_VIEW", "PSIIC_HEAD"),
#         ("_CEL_AP_CASES_VIEW", "TBSLT"),
#         ("_CEL_AP_CASES_VIEW", "LFA1"),
#         ("_CEL_AP_CASES_VIEW", "_CEL_AP_CASES_VIEW_1"),
#         ("_CEL_AP_CASES_VIEW", "REGUP"),
#         ("_CEL_AP_CASES_VIEW", "T052U"),
#         ("_CEL_AP_CASES_VIEW", "EKPO"),
#         # PSIIC_HEAD
#         ("PSIIC_HEAD", "TMP_AP_BKPF_BSEG_1"),
#         ("PSIIC_HEAD", "CDPOS"),
#         ("PSIIC_HEAD", "BKPF"),
#         ("PSIIC_HEAD", "TMP_AP_BKPF_BSEG"),
#         ("PSIIC_HEAD", "_CEL_AP_CASES_VIEW_1"),
#         ("PSIIC_HEAD", "_CEL_AP_CASES_VIEW"),
#         # TBSLT
#         ("TBSLT", "TMP_AP_BKPF_BSEG_1"),
#         ("TBSLT", "BSEG"),
#         ("TBSLT", "TMP_AP_BKPF_BSEG"),
#         ("TBSLT", "_CEL_AP_CASES_VIEW_1"),
#         ("TBSLT", "_CEL_AP_CASES_VIEW"),
#         # LFA1
#         ("LFA1", "TMP_AP_BKPF_BSEG"),
#         ("LFA1", "BKPF"),
#         ("LFA1", "BSEG"),
#         ("LFA1", "TMP_AP_BKPF_BSEG_1"),
#         ("LFA1", "_CEL_AP_CASES_VIEW"),
#         # REGUP
#         ("REGUP", "_CEL_AP_CASES_VIEW"),
#         ("REGUP", "TMP_AP_BKPF_BSEG"),
#         # BSEC
#         ("BSEC", "BSEG"),
#         ("BSEC", "_CEL_AP_CASES_VIEW_1"),
#         # _CEL_AP_CASES_VIEW_1
#         ("_CEL_AP_CASES_VIEW_1", "BSEC"),
#         ("_CEL_AP_CASES_VIEW_1", "LFA1"),
#         ("_CEL_AP_CASES_VIEW_1", "TMP_AP_BKPF_BSEG"),
#         ("_CEL_AP_CASES_VIEW_1", "TVZBT"),
#         ("_CEL_AP_CASES_VIEW_1", "T042Z"),
#         ("_CEL_AP_CASES_VIEW_1", "TBSLT"),
#         ("_CEL_AP_CASES_VIEW_1", "BKPF"),
#         ("_CEL_AP_CASES_VIEW_1", "BSEG"),
#         ("_CEL_AP_CASES_VIEW_1", "LFB1"),
#         ("_CEL_AP_CASES_VIEW_1", "PSIIC_HEAD"),
#         ("_CEL_AP_CASES_VIEW_1", "TMP_AP_BKPF_BSEG_1"),
#         ("_CEL_AP_CASES_VIEW_1", "_CEL_AP_CASES_VIEW"),
#         ("_CEL_AP_CASES_VIEW_1", "EKPO"),
#         ("_CEL_AP_CASES_VIEW_1", "T052U"),
#         # T052U
#         ("T052U", "_CEL_AP_CASES_VIEW_1"),
#         ("T052U", "TMP_AP_BKPF_BSEG"),
#         ("T052U", "BSEG"),
#         ("T052U", "LFB1"),
#         ("T052U", "TMP_AP_BKPF_BSEG_1"),
#         ("T052U", "_CEL_AP_CASES_VIEW"),
#         # EKPO
#         ("EKPO", "_CEL_AP_CASES_VIEW_1"),
#         ("EKPO", "TMP_AP_BKPF_BSEG"),
#         ("EKPO", "_CEL_AP_CASES_VIEW"),
#     ],
# }

# test_data2 = {
#     "nodes": ["A", "B", "C", "D", "E", "F"],
#     "edges": [
#         ("A", "B"),
#         ("A", "C"),
#         ("B", "A"),
#         ("B", "C"),
#         ("B", "D"),
#         ("C", "A"),
#         ("C", "B"),
#         ("C", "D"),
#         ("C", "E"),
#         ("D", "B"),
#         ("D", "C"),
#         ("D", "E"),
#         ("D", "F"),
#         ("E", "C"),
#         ("E", "D"),
#         ("F", "D"),
#     ],
# }


class TestGraph1(unittest.TestCase):
    def setUp(self):
        self.g = Graph(test_data2["nodes"], test_data2["edges"])
        self.src = "A"
        self.des = "A"
        self.selected_node_ids = ["A", "B"]

    def tearDown(self):
        self.g = None
        self.src = None
        self.des = None
        self.selected_node_ids = None

    def test_get_shortest_path(self):
        expected = 0
        result = Graph.get_shortest_path(self.g, self.src, self.des)
        self.assertEqual(expected, result)

    def test_get_subtrees(self):

        expected = [
            [("A", "B"), ("A", "C"), ("B", "D"), ("C", "E"), ("D", "F")],
            [
                ("B", "A"),
                ("B", "C"),
                ("B", "D"),
                ("C", "E"),
                ("D", "F"),
            ],
        ]
        result = Graph.get_subtrees(self.g, self.selected_node_ids)
        self.assertEqual(expected, result)


class TestGraph2(unittest.TestCase):
    def setUp(self):
        self.g = Graph(test_data2["nodes"], test_data2["edges"])
        self.src = "F"
        self.des = "A"
        self.selected_node_ids = ["A", "E"]

    def tearDown(self):
        self.g = None
        self.src = None
        self.des = None
        self.selected_node_ids = None

    def test_get_shortest_path(self):
        expected = 3
        result = Graph.get_shortest_path(self.g, self.src, self.des)
        self.assertEqual(expected, result)

    def test_get_subtrees(self):

        expected = [
            [("A", "B"), ("A", "C"), ("B", "D"), ("C", "E"), ("D", "F")],
            [("E", "C"), ("E", "D"), ("C", "A"), ("C", "B"), ("D", "F")],
        ]
        result = Graph.get_subtrees(self.g, self.selected_node_ids)
        self.assertEqual(expected, result)


class TestGraph3(unittest.TestCase):
    def setUp(self):
        self.g = Graph(test_data1["nodes"], test_data1["edges"])
        self.src = "CDHDR"
        self.des = "CDHDR"
        self.selected_node_ids = ["CDHDR", "CDPOS"]

    def tearDown(self):
        self.g = None
        self.src = None
        self.des = None
        self.selected_node_ids = None

    def test_get_shortest_path(self):
        expected = 0
        result = Graph.get_shortest_path(self.g, self.src, self.des)
        self.assertEqual(expected, result)

    def test_get_subtrees(self):

        expected = [
            [
                ("CDHDR", "CDPOS"),
                ("CDHDR", "USR02"),
                ("CDPOS", "BKPF"),
                ("CDPOS", "TMP_AP_BKPF_BSEG"),
                ("CDPOS", "PSIIC_HEAD"),
                ("CDPOS", "_CEL_AP_CASES_VIEW"),
                ("CDPOS", "TMP_AP_BKPF_BSEG_1"),
                ("BKPF", "LFA1"),
                ("BKPF", "_CEL_AP_CASES_VIEW_1"),
                ("BKPF", "BSEG"),
                ("BKPF", "REGUP"),
                ("BKPF", "LFB1"),
                ("BKPF", "SWW_WI2OBJ"),
                ("BKPF", "T003T"),
                ("TMP_AP_BKPF_BSEG", "T052U"),
                ("TMP_AP_BKPF_BSEG", "TBSLT"),
                ("TMP_AP_BKPF_BSEG", "EKPO"),
                ("TMP_AP_BKPF_BSEG", "T042Z"),
                ("TMP_AP_BKPF_BSEG", "TVZBT"),
                ("_CEL_AP_CASES_VIEW_1", "BSEC"),
                ("SWW_WI2OBJ", "SWWLOGHIST"),
            ],
            [
                ("CDPOS", "CDHDR"),
                ("CDPOS", "BKPF"),
                ("CDPOS", "TMP_AP_BKPF_BSEG"),
                ("CDPOS", "PSIIC_HEAD"),
                ("CDPOS", "_CEL_AP_CASES_VIEW"),
                ("CDPOS", "TMP_AP_BKPF_BSEG_1"),
                ("CDHDR", "USR02"),
                ("BKPF", "LFA1"),
                ("BKPF", "_CEL_AP_CASES_VIEW_1"),
                ("BKPF", "BSEG"),
                ("BKPF", "REGUP"),
                ("BKPF", "LFB1"),
                ("BKPF", "SWW_WI2OBJ"),
                ("BKPF", "T003T"),
                ("TMP_AP_BKPF_BSEG", "T052U"),
                ("TMP_AP_BKPF_BSEG", "TBSLT"),
                ("TMP_AP_BKPF_BSEG", "EKPO"),
                ("TMP_AP_BKPF_BSEG", "T042Z"),
                ("TMP_AP_BKPF_BSEG", "TVZBT"),
                ("_CEL_AP_CASES_VIEW_1", "BSEC"),
                ("SWW_WI2OBJ", "SWWLOGHIST"),
            ],
        ]
        result = Graph.get_subtrees(self.g, self.selected_node_ids)
        self.assertEqual(expected, result)


class TestGraph4(unittest.TestCase):
    def setUp(self):
        self.g = Graph(test_data1["nodes"], test_data1["edges"])
        self.src = "CDHDR"
        self.des = "LFB1"
        self.selected_node_ids = ["BSEC", "T003T"]

    def tearDown(self):
        self.g = None
        self.src = None
        self.des = None
        self.selected_node_ids = None

    def test_get_shortest_path(self):
        expected = 3
        result = Graph.get_shortest_path(self.g, self.src, self.des)
        self.assertEqual(expected, result)

    def test_get_subtrees(self):

        expected = [
            [
                ("BSEC", "BSEG"),
                ("BSEC", "_CEL_AP_CASES_VIEW_1"),
                ("BSEG", "BKPF"),
                ("BSEG", "TMP_AP_BKPF_BSEG"),
                ("BSEG", "LFA1"),
                ("BSEG", "TBSLT"),
                ("BSEG", "_CEL_AP_CASES_VIEW"),
                ("_CEL_AP_CASES_VIEW_1", "TVZBT"),
                ("_CEL_AP_CASES_VIEW_1", "T042Z"),
                ("_CEL_AP_CASES_VIEW_1", "LFB1"),
                ("_CEL_AP_CASES_VIEW_1", "PSIIC_HEAD"),
                ("_CEL_AP_CASES_VIEW_1", "TMP_AP_BKPF_BSEG_1"),
                ("_CEL_AP_CASES_VIEW_1", "EKPO"),
                ("_CEL_AP_CASES_VIEW_1", "T052U"),
                ("BKPF", "REGUP"),
                ("BKPF", "SWW_WI2OBJ"),
                ("BKPF", "USR02"),
                ("BKPF", "T003T"),
                ("BKPF", "CDPOS"),
                ("SWW_WI2OBJ", "SWWLOGHIST"),
                ("USR02", "CDHDR"),
            ],
            [
                ("T003T", "BKPF"),
                ("T003T", "_CEL_AP_CASES_VIEW"),
                ("BKPF", "TMP_AP_BKPF_BSEG"),
                ("BKPF", "LFA1"),
                ("BKPF", "_CEL_AP_CASES_VIEW_1"),
                ("BKPF", "BSEG"),
                ("BKPF", "PSIIC_HEAD"),
                ("BKPF", "REGUP"),
                ("BKPF", "LFB1"),
                ("BKPF", "SWW_WI2OBJ"),
                ("BKPF", "USR02"),
                ("BKPF", "TMP_AP_BKPF_BSEG_1"),
                ("BKPF", "CDPOS"),
                ("_CEL_AP_CASES_VIEW", "T042Z"),
                ("_CEL_AP_CASES_VIEW", "TVZBT"),
                ("_CEL_AP_CASES_VIEW", "TBSLT"),
                ("_CEL_AP_CASES_VIEW", "T052U"),
                ("_CEL_AP_CASES_VIEW", "EKPO"),
                ("_CEL_AP_CASES_VIEW_1", "BSEC"),
                ("SWW_WI2OBJ", "SWWLOGHIST"),
                ("USR02", "CDHDR"),
            ],
        ]
        result = Graph.get_subtrees(self.g, self.selected_node_ids)
        self.assertEqual(expected, result)


class TestGraph5(unittest.TestCase):
    def setUp(self):
        self.g = Graph(test_data1["nodes"], test_data1["edges"])
        self.src = "CDHDR"
        self.des = "BKPF"

    def tearDown(self):
        self.g = None
        self.src = None
        self.des = None

    def test_get_shortest_path(self):
        expected = 2
        # CDHDR ->BKPF = 2 ['CDHDR', 'USR02', 'BKPF']
        result = Graph.get_shortest_path(self.g, self.src, self.des)
        self.assertEqual(expected, result)


class TestGraph6(unittest.TestCase):
    def setUp(self):
        self.g = Graph(test_data1["nodes"], test_data1["edges"])
        self.src = "CDHDR"
        self.des = "CDPOS"

    def tearDown(self):
        self.g = None
        self.src = None
        self.des = None

    def test_get_shortest_path(self):
        expected = 1
        # CDHDR ->CDPOS = 1 ['CDHDR', 'CDPOS']
        result = Graph.get_shortest_path(self.g, self.src, self.des)
        self.assertEqual(expected, result)


if __name__ == "__main__":

    suite = unittest.TestSuite()
    suite.addTest(TestGraph3("test_get_shortest_path"))
    suite.addTest(TestGraph3("test_get_subtrees"))
    unittest.TextTestRunner(verbosity=2).run(suite)

    suite = unittest.TestSuite()
    suite.addTest(TestGraph4("test_get_shortest_path"))
    suite.addTest(TestGraph4("test_get_subtrees"))
    unittest.TextTestRunner(verbosity=2).run(suite)

    suite = unittest.TestSuite()
    suite.addTest(TestGraph6("test_get_shortest_path"))
    unittest.TextTestRunner(verbosity=2).run(suite)
